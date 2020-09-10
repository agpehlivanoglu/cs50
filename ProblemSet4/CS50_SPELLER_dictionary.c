// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>


#include "dictionary.h"

// Represents number of buckets in a hash table
#define N 26

// To count the number of words in dictionary
int counter = 0;

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Represents a hash table
node *hashtable[N];


// Hashes word to a number between 0 and 25, inclusive, based on its first letter
unsigned int hash(const char *word)
{
    return tolower(word[0]) - 'a';
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Initialize hash table
    for (int i = 0; i < N; i++)
    {
        hashtable[i] = NULL;
    }

    // Open dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        unload();
        return false;
    }

    // Buffer for a word
    char phrase[LENGTH + 1];

    // Insert words into hash table
    while (fscanf(file, "%s", phrase) != EOF)
    {
        int fletter = hash(phrase); // This is the hash code

        // Allocate space for word
        node *n = malloc(sizeof(node));
        if (!n) // Chechking whether there exists enough memory for malloc
        {
            unload();
            return false;
        }

        // Add number to list
        strcpy(n->word, phrase);
        n->next = NULL;

        // Linking nodes together for each bucket of array
        if (hashtable[fletter])
        {
            n->next = hashtable[fletter];
            hashtable[fletter] = n;
            counter++;
            n = NULL;
        }
        else
        {
            hashtable[fletter] = n;
            n = NULL;
            counter++;
        }
    }

    // Close dictionary
    fclose(file);

    // Indicate success
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    if (counter != 0)
    {
        return counter;
    }
    else
    {
        return 0;
    }
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int fletter = hash(word);
    if (hashtable[fletter])
    {
        for (node *cursor = hashtable[fletter]; cursor != NULL; cursor = cursor->next) // This code moves cursor to the next node with each loop
        {
            if (strcasecmp(word, cursor->word) == 0) // If input word is same with node.word, it returns to 0
            {
                return true;
            }
        }
    }

    return false;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    int bad = 0;
    for (int i = 0; i < N; i++)
    {
        if (hashtable[i])
        {
            node *cursor = hashtable[i];
            while (cursor != NULL) // Creating a loop and a dummy temp: https://www.youtube.com/watch?v=qkC4l0pUvCk&list=PLhQjrBD2T382T4b6jjwX_qbU23E_Unwcz&index=6&ab_channel=CS50
            {
                node *tmp = cursor;
                cursor = cursor->next;
                free(tmp);
                bad++;
            }
        }
    }

    if (bad != 0)
    {
        return true;
    }

    return false;

}
