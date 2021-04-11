#include <cs50.h>
#include <stdio.h>

int main(void)
{

    int startsize;
    int endsize;
    int years = 0;

    // TODO: Prompt for start size
    do
    {
        startsize = get_int("Start size?: ");
    }
    while (startsize < 9);

    // TODO: Prompt for end size
    do
    {
        endsize = get_int("End size?: ");
    }
    while (endsize < startsize);

    // TODO: Calculate number of years until we reach threshold
    if (startsize == endsize)
    {
        years = 0;
    }
    else
    {
        do
        {
            startsize = startsize + (startsize / 3) - (startsize / 4);
            years++;
        }
        while (endsize > startsize);
    }

    // TODO: Print number of years
    printf("Years: %i", years);
}