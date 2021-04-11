// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include "dictionary.h"
#include <strings.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N] = {NULL};

unsigned int wordcount = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int a = hash(word);

    node *cursor = NULL;
    cursor = table[a];

    while (cursor != NULL)
    {
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        else
        {
            cursor = cursor->next;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    return tolower(word[0]) - 'a';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    char buffer[LENGTH + 1];
    while (fscanf(file, "%s", buffer) != EOF)
    {
        node *element = malloc(sizeof(node));
        if (element == NULL)
        {
            return false;
        }
        strcpy(element->word, buffer);

        int a = hash(element->word);

        if (table[a] == NULL)
        {
            element->next = NULL;
            table[a] = element;
        }
        else
        {
            element->next = table[a];
            table[a] = element;
        }
        wordcount++;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return wordcount;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *tmp = table[i];
        node *cursor = table[i];
        while (cursor != NULL)
        {
            cursor = cursor->next;
            free(tmp);
            tmp = cursor;
        }
        free(cursor);
    }
    return true;
}