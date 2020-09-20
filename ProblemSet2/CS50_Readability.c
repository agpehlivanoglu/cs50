#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    string text = get_string("Text: ");
    int n = strlen(text);
    float letter = 0;
    float spaces = 0;
    float sentences = 0;

    for (int i = 0; i < n; i++)
    {
        if (isalpha(text[i])) // number of letters
        {
            letter++;
        }

        else if (text[i] == 32) // number of words (indirectly) assuming a sentence will not start or end with a space, and that a sentence will not have multiple spaces in a row.
        {
            spaces++;
        }

        else if (text[i] == 46 || text[i] == 33 || text[i] == 63) // number of sentences assuming all periods mean the sentence is over
        {
            sentences++;
        }

    }

    float words = spaces + 1;
    float L = (letter * 100) / words; // L is the average number of letters per 100 words in the text
    float S = (sentences * 100) / words; // S is the average number of sentences per 100 words in the text.

    // L is the average number of letters per 100 words in the text, and S is the average number of sentences per 100 words in the text.
    float index = (0.0588 * L) - (0.296 * S) - 15.8;
    index = round(index);

    if (index >= 16)
        printf("Grade 16+\n");
    else if (index < 1)
        printf("Before Grade 1\n");
    else
        printf("Grade %.0f\n", index);
}
