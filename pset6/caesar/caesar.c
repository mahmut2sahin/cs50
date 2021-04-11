#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

bool digit_check(string input);
void decrypt(string text, int key);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        if (digit_check(argv[1]))
        {
            //printf("Success!\n");
            int key = atoi(argv[1]);
            //printf("%i\n", key);
            string plaintext = get_string("plaintext: ");
            decrypt(plaintext, key);
            return 0;
        }
        else
        {
            printf("Usage: ./caesar key\n");
            return 31;
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

bool digit_check(string input)
{
    int n = strlen(input);
    for (int i = 0; i < n; i++)
    {
        if (isdigit(input[i]))
        {
        }
        else
        {
            return false;
        }
    }
    return true;
}

void decrypt(string text, int key)
{
    int n = strlen(text);
    int shift = key % 26;
    printf("ciphertext: ");
    for (int i = 0; i < n; i++)
    {
        if (text[i] >= 65 && text[i] <= 90)
        {
            if (text[i] + shift > 90)
            {
                printf("%c", ((text[i] + shift) % 90) + 64);
            }
            else
            {
                printf("%c", text[i] + shift);
            }
        }
        else if (text[i] >= 97 && text[i] <= 122)
        {
            if (text[i] + shift > 122)
            {
                printf("%c", ((text[i] + shift) % 122) + 96);
            }
            else
            {
                printf("%c", text[i] + shift);
            }
        }
        else
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
}