#include <stdio.h>
#include <math.h>
#include <cs50.h>

float getValue(void);
int coins(int cents);

int main(void)
{
    // Make sure the user prompts a valid value
    float owed = getValue();
    // Convert dollars to cents
    int cents = round(owed * 100);
    // Prints how many coins are needed, breaks line
    printf("%d\n", coins(cents));
}

// Counts the least number of coins needed to cover change
int coins(int cents)
{
    int count = 0;

    // Loops decreasing cents by the biggest coin possible until cents = 0
    while (cents > 0)
    {
        if (cents >= 25)
        {
            cents -= 25;
            count++;
        }
        else if (cents >= 10)
        {
            cents -= 10;
            count++;
        }
        else if (cents >= 5)
        {
            cents -= 5;
            count++;
        }
        else
        {
            cents -= 1;
            count++;
        }
    }
    return count;
}

// Prompts user for a valid change value
float getValue(void)
{
    // Change is initialized before the loop otherwise while won't get it
    float change;
    do
    {
        // get_float is a function from CS50 library
        change = get_float("Change owed: ");
    }
    while (change < 0.00);

    return change;
}