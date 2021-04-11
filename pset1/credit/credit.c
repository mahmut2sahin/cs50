#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    long cardnumber = get_long("What is your credit number without hyphens?\n");

    long digitcounter = 0;
    for (int i = 0; (cardnumber / pow(10, i)) >= 1; i++)
    {
        digitcounter++;
    }
    //printf("%ld\n", digitcounter);


    long divider = 100, digit = 0, sum = 0;
    for (divider = 100; divider < cardnumber * 10; divider *= 100)
    {
        digit = cardnumber % divider;
        digit = (digit / (divider / 10)) * 2;
        if (digit >= 10)
        {
            sum += digit % 10;
            sum += digit / 10;
        }
        else
        {
            sum += digit;
        }
        digit = 0;
    }

    for (divider = 10; divider < cardnumber * 10; divider *= 100)
    {
        digit = cardnumber % divider;
        digit = digit / (divider / 10);
        sum += digit;
        digit = 0;
    }
    //printf("%ld\n", sum);

    if (sum % 10 != 0)
    {
        printf("INVALID\n");
    }
    else
    {
        if (digitcounter == 15)
        {
            long two_digit_divider = pow(10, 13);
            int first_two_digits = cardnumber / two_digit_divider;
            if (first_two_digits == 34 || first_two_digits == 37)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (digitcounter == 16)
        {
            long firstdigitdivider = pow(10, 15);
            if ((cardnumber / firstdigitdivider) == 4)
            {
                printf("VISA\n");
            }
            else
            {
                long mctwodigits = pow(10, 14);
                int first_two_digits_mc = cardnumber / mctwodigits;
                if (first_two_digits_mc == 51 || first_two_digits_mc == 52 || first_two_digits_mc == 53 || first_two_digits_mc == 54
                    || first_two_digits_mc == 55)
                {
                    printf("MASTERCARD\n");
                }
                else
                {
                    printf("INVALID\n");
                }
            }
        }
        else if (digitcounter == 13)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
}


























