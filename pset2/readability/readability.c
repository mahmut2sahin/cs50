#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters(string textf);
int count_words(string wordf);
int count_sentences(string sentencef);

int main(void)
{
    string text = get_string("Text: ");
    //printf("%i Letter(s)\n", count_letters(text));
    //printf("%i Word(s)\n", count_words(text));
    //printf("%i Sentence(s)\n", count_sentences(text));
    int letters = count_letters(text), words = count_words(text), sentences = count_sentences(text);
    float L, S;
    //index = 0.0588 * L - 0.296 * S - 15.8

    if (words <= 100)
    {
        L = (100 / (float) words) * letters;
        S = (100 / (float) words) * sentences;
    }
    else
    {
        L = ((float) words / 100) * letters;
        S = ((float) words / 100) * sentences;
    }

    float index = 0.0588 * L - 0.296 * S - 15.8;
    if (round(index) >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (round(index) < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %.f\n", round(index));
    }
}

int count_letters(string textf)
{
    int letters = 0;
    int n = strlen(textf);
    for (int i = 0; i < n; i++)
    {
        if ((textf[i] >= 65 && textf[i] <= 90) || (textf[i] >= 97 && textf[i] <= 122))
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string wordf)
{
    int n = strlen(wordf);
    int words = 0;
    for (int i = 0; i < n + 1; i++)
    {
        if (wordf[i] == 32 || wordf[i] == 0)
        {
            words++;
        }
    }
    return words;
}

int count_sentences(string sentencef)
{
    int n = strlen(sentencef);
    int sentences = 0;
    for (int i = 0; i < n; i++)
    {
        if (sentencef[i] == 33 || sentencef[i] == 46 || sentencef[i] == 63)
        {
            sentences++;
        }
    }
    return sentences;
}
