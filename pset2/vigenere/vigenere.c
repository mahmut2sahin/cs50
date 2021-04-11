#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

bool alpha_check(string key);
void decrypt(string key, string text);

int main(int argc, string argv[])
{
    if (argc == 2 && alpha_check(argv[1]))
    {
        string text = get_string("plaintext: ");
        decrypt(argv[1], text);
        return 0;
    }
    else
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }
}

bool alpha_check(string key)
{
    int n = strlen(key);
    for (int i = 0; i < n; i++)
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

void decrypt(string key, string text)
{
    int txtl = strlen(text);
    int keyl = strlen(key);
    int skey[txtl];
    printf("ciphertext: ");
    int n = 0;

    for (int k = 0; k < keyl; k++)
    {
        key[k] = toupper(key[k]);
    }

    for (int i = 0; i < txtl; i++)
    {
        if (isalpha(text[i]))
        {
            {
                if (isupper(text[i]))
                {
                    skey[n] = key[n % keyl] % 65;
                    if (skey[n] + text[i] <= 90)
                    {
                        printf("%c", text[i] + skey[n]);
                    }
                    else
                    {
                        printf("%c", (text[i] + skey[n]) % 91 + 65);
                    }
                }
                else
                {
                    skey[n] = key[n % keyl] % 65;
                    if (skey[n] + text[i] <= 122)
                    {
                        printf("%c", text[i] + skey[n]);
                    }
                    else
                    {
                        printf("%c", (text[i] + skey[n]) % 123 + 97);
                    }
                }
            }
            n++;
        }
        else
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
}