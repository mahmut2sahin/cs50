#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float dollars;
    do
    {
        dollars = get_float("Change owed in dollars?\n"); //prompt owed dollars value
    }
    while (dollars < 0);

    int cents = round(dollars * 100);
    int coins = 0;

    for (; cents >= 25; cents = cents - 25)
    {
        coins++;
    }

    for (; cents >= 10; cents = cents - 10)
    {
        coins++;
    }

    for (; cents >= 5; cents = cents - 5)
    {
        coins++;
    }

    for (; cents >= 1; cents = cents - 1)
    {
        coins++;
    }

    printf("%i", coins);
}
