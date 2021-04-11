#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    int spacel;
    int hashcounterl;
    int hashcounterr;

    //prompt the height
    do
    {
        height = get_int("Height: ?\n");
    }
    while (height < 1 || height > 8);

    //building the structure
    for (int i = 0; i < height; i++)
    {
        for (spacel = 0; spacel < height - (i + 1); spacel++)
        {
            printf(" ");
        }

        for (hashcounterl = 0; hashcounterl < height - spacel; hashcounterl++)
        {
            printf("#");
        }
        printf("  ");

        for (hashcounterr = 0; hashcounterr < hashcounterl; hashcounterr++)
        {
            printf("#");
        }
        printf("\n");
    }
}