#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void check(string s);
int shift(char c);
int main(int argc, string argv[])
{
    //if argument count does not equal 2, exit and return 1
    if (argc != 2)
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }
    // checks to make sure that each character of that command line argument is a decimal digit
    else
    {
        check(argv[1]);      
    }
    
    int numkey = strlen(argv[1]); //gets the total number of characters in argument
    //creating an array to store all of the character numbers
    int key[numkey];
    for (int l=0; l<numkey; l++)
    {
        key[l] = shift(argv[1][l]);
    }

    string s = get_string("plaintext: ");  //get plaintext from user to encrypt
    printf("ciphertext: ");

    for (int i = 0, j = 0, n = strlen(s); i < n; i++) //using just one loop, but keeping track of j myself
    {
        if (j >= numkey){j = 0;} //If the length of the keyword is, say, 4 characters, then the last character of that keyword can be found at keyword[3]. Then, for the next character you encipher, you’ll want to use keyword[0].
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
            s[i] = ((s[i] + key[j]) - 65) % 26;
            printf("%c", s[i] + 65);
            j++;
        }
        else if (islower(s[i])) //to keep lowercase letters remain lowercase.
        {
            // Same thing but substracting 97
            s[i] = ((s[i] + key[j]) - 97) % 26;
            printf("%c", s[i] + 97);
            j++;
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
                 if (!isalpha(s[j])) //isdigit is the funciton that checks it
                 {
                    printf("Usage: ./vigenere keyword\n");
                    exit(1);
                 }
             }   
        }
}

//function that converts a character into the correct shift value
int shift(char c)
{
    int k = 0;
    if (isupper(c)) //to keep uppercase letters remain uppercase.
    {
    // Subtract your ASCII character by 65. It'll lead to output between 0 to 25 (inclusive).
    //Take a modulo 26, to wrap around your result.
        k = c;
        k = ((k - 65) % 26);
    }
    else if (islower(c)) //to keep lowercase letters remain lowercase.
    {
        // Same thing but substracting 97
        k = c;
        k = ((k - 97) % 26);
    }
      return k;
}
