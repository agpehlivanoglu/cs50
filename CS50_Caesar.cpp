#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void check(string s);
int main(int argc, string argv[])
{
    //if argument count does not equal 2, exit and return 1
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // checks to make sure that each character of that command line argument is a decimal digit
    else
    {
        check(argv[1]);      
    }
    
    // if both conditions are true, we access the "key(k)" data
    int key = atoi(argv[1]);
    
    string s = get_string("plaintext: ");  //get plaintext from user to encrypt
    int n = strlen(s); // length of 
    printf("ciphertext: ");
    
    // c = (p + k) % 26;    
    //iterate over the characters in the string
    //p represents the position in the alphabet of a plaintext letter
    //c likewise represents a position in the alphabet

    for (int i=0; i<n; i++)
    {
        if (!isalpha(s[i])) //to not changing the punctuation marks or empty spaces
        {
            printf("%c", s[i]);
            continue;
        }
            if (isupper(s[i])) //to keep uppercase letters remain uppercase.
            {
                // Subtract your ASCII character by 65. It'll lead to output between 0 to 25 (inclusive).
                // Add the displacement (shift distance).
                //Take a modulo 26, to wrap around your result.
                // Add 65 back again.
                s[i] = ((s[i] + key) - 65) % 26;
                printf("%c", s[i] + 65);
            }
            else if (islower(s[i])) //to keep lowercase letters remain lowercase.
            {
                // Same thing but substracting 97
                s[i] = ((s[i] + key) - 97) % 26;
                printf("%c", s[i] + 97);
            }
    }
    printf("\n");
}

//function that makes sure that each character of that command line argument is a decimal digit
void check(string s)
{
    for (int i=1; i<2; i++)
        {
             for(int j=0; j<strlen(s); j++)
             {
                 if (!isdigit(s[j])) //isdigit is the funciton that checks it
                 {
                    printf("Usage: ./caesar key\n");
                    exit(0);
                 }
             }   
        }
}
