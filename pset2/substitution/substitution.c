#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

bool alpha_check(string key);
void decrypt(string text, string key);
bool duplicheck(string key);

int main(int argc, string argv[])
{
    if (argc != 2 || strlen(argv[1]) != 26)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (duplicheck(argv[1]))
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (alpha_check(argv[1]))
    {
        string text = get_string("plaintext: ");
        decrypt(text, argv[1]);
        return 0;
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
}

bool alpha_check(string key)
{
    for (int i = 0; i < 26; i++)
    {
        if (isalpha(key[i]))
        {
        }
        else
        {
            return false;
        }
    }
    return true;
}

void decrypt(string text, string key)
{
    int n = strlen(text);
    printf("ciphertext: ");
    for (int i = 0; i < n; i++)
    {
        if (text[i] >= 65 && text[i] <= 90)
        {
            int x = text[i] % 65;
            printf("%c", toupper(key[x]));
        }
        else if (text[i] >= 97 && text[i] <= 122)
        {
            int x = text[i] % 97;
            printf("%c", tolower(key[x]));
        }
        else
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
}

bool duplicheck(string key)
{
    for (int i = 0; i < 26; i++)
    {
        for (int y = 0; y < 26; y++)
        {
            if (i == y)
            {
            }
            else if (key[i] == key[y])
            {
                return true;
            }
        }
    }
    return false;
}