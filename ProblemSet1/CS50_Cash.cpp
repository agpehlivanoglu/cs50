#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float dollars = -1;
    while (dollars<0)
    {
        dollars = get_float("Change owed in dollars: ");
    }

    int cents = round(dollars * 100);
    printf("%i in cents\n",cents);
    int remaining = cents;
    int x = 0;
    
    while (remaining>=25)
    {
        x++;
        remaining -= 25;
    }

    while (remaining>=10)
    {
        x++;
        remaining -= 10;
    }

    
    while (remaining>=5)
    {
        x++;
        remaining -= 5;
    }

    
    while (remaining>=1)
    {
        x++;
        remaining -= 1;
    }

    printf("The minimal number of coins you’re dispensing for the customer is %i\n",x);
}
