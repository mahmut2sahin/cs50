#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    int space;
    //prompt the height
    do
    {
        height = get_int("Height: ?\n");
    }
    while (height < 1 || height > 8);

    for (int i = 0; i < height; i++)
    {
        for (space = 0; space < height - (i + 1); space++)
        {
            printf(" ");
        }

        for (int hashcounter = 0; hashcounter < height - space; hashcounter++)
        {
            printf("#");
        }
        printf("\n");
    }
}
