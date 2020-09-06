// Enhances a BMP file
// the first argument must be a positive integer less than or equal to 100
// the second argument must be the name of a BMP to be resized
// the third argument must be the name of the resized version to be written


#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: copy infile outfile\n");
        printf("Usage: ./resize n infile outfile\n");
        return 1;
    }

    for (int val = 0; val < strlen(argv[1]); val++)
    {
        if (!isdigit(argv[1][val]))
        {
            fprintf(stderr, "Usage: n must be a positive integer\n");
            printf("Usage: ./resize n infile outfile\n");
            printf("The first argument must be a positive integer less than or equal to 100,\n");
            return 5;
        }
    }

    int n = atoi(argv[1]); // // making argv[1] is integer
    if (n < 1 || n > 100)
    {
        printf("Usage: ./resize n infile outfile\n");
        printf("the first argument must be a positive integer less than or equal to 100,\n");
        return 6;
    }


    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }


    // determine infile's padding for scanlines
    int inpadding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // In this section, We will update outfile's header info
    // declaring new variables to keep track of both infile and outfile headers
    BITMAPINFOHEADER bi_out = bi;
    BITMAPFILEHEADER bf_out = bf;

    bi_out.biWidth  = bi_out.biWidth * n; // does not include padding
    bi_out.biHeight = bi_out.biHeight * n;

    // determine outfile's padding for scanlines
    int outpadding  = (4 - (bi_out.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    bi_out.biSizeImage = ((sizeof(RGBTRIPLE) * bi_out.biWidth) + outpadding) * abs(bi_out.biHeight); // includes pixels and padding
    bf_out.bfSize = bi_out.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER); // includes pixels, padding and headers


    // write outfile's BITMAPFILEHEADER
    fwrite(&bf_out, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi_out, sizeof(BITMAPINFOHEADER), 1, outptr);



    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        RGBTRIPLE* arr = malloc(bi_out.biWidth * sizeof(RGBTRIPLE));
//OR -> RGBTRIPLE arr[bi_out.biWidth];

        // iterate over pixels in scanline
        for (int j = 0; j < bi.biWidth; j++)
        {
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            // save each RGB triple into temp array n times (to scale horizontally by n)
            for (int l = 0; l < n; l++)
                arr[n*j+l] = triple; // Instead of using just l, we need to find a way to "move over" based on how far along your original scanline (j) you are.
        }

        // write temp storage array n times (to scale vertically by n)
        for (int v = 0; v < n; v++)
        {
            fwrite(arr, sizeof(RGBTRIPLE) * bi_out.biWidth, 1, outptr);
//OR ->     fwrite(&arr[0], sizeof(arr), 1, outptr);

            // add padding
            for (int k = 0; k < outpadding; k++)
            {
                fputc(0x00, outptr);
            }
        }

        // skip over old padding, if any
        fseek(inptr, inpadding, SEEK_CUR);
        free(arr);
    }


    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);


    // success
    return 0;
}

