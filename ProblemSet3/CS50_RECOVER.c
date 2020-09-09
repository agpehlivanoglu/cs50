// To execute: ./recover card.raw

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: input exactly one command-line argument\n");
        return 1;
    }

    char* name = argv[1]; //filename
    FILE *file = fopen(argv[1], "r");  // open input file

    if (!file)
    {
        fprintf(stderr, "Usage: %s cannot be opened for reading\n", name);
        return 2;
    }

    // making declerations
    typedef uint8_t  BYTE; //defining a type
    int numjpg = 0; //to count recovered imgage number
    BYTE buffer[512]; //???OR -> BYTE* buffer = malloc(512 * sizeof(BYTE));
    int b = 512;
    char filename[8]; //name of jpeg is stored in this array 000.jpg\0
    FILE *img = NULL;

    while (fread(buffer, sizeof(BYTE), 512, file) == 512) //"repeat until end of memory card" fread returns the value of the input number, when we reach EOF it returns a different number
    {

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) // If it's start of a new JPEG
        {
            if (numjpg == 0) // If it is the first JPEG
            {
                sprintf(filename, "%0.3i.jpg", numjpg);  //name outfile using sprintf
                numjpg += 1;
                img = fopen(filename, "w");
                fwrite(buffer, sizeof(BYTE), 512, img);
            }
            else
            {
                fclose(img);
                sprintf(filename, "%0.3i.jpg", numjpg);  //name outfile using sprintf
                numjpg += 1;
                img = fopen(filename, "w");
                fwrite(buffer, sizeof(BYTE), 512, img);

            }
        }

        else
        {
            if (img != NULL) // If we already found a JPEG
            {
                fwrite(buffer, sizeof(BYTE), 512, img);
            }
        }

    }

    // close infile
    fclose(file);

    // close outfile
    fclose(img);
    exit(0);
}

