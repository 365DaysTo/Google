#include <cs50.h>
#include <stdio.h>

// Let's identify the function
int get_positive_int(string prompt);

// Main function
int main(void)
{
    // Let's ask the height from the user
    int start_number = get_positive_int("Height: ");

    // Now we should loop inside to build every slash block
    for (int height = 0; height < start_number; height++)
    {
        for (int dots = start_number - height - 2; dots >= 0; dots--)
        {
            // Let's print some dots and remove the spaces laters
            printf(" ");
        }
        // Loop the rows
        for (int row = 0; row <= height; row++)
        {
            printf("#");
        }
        printf("\n");
    }
}

// Get the positive number from a user and executethe function
int get_positive_int(string prompt)
{
    int number;
    do // do loop for runing code at least once
    {
        number = get_int("%s", prompt);
    }
    while (number < 1 || number > 8); // to display digits from 1 to 8 inclusive
    return number; //will ask again if anything but 1-8 digits
}