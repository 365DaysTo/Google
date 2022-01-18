
#include <cs50.h>
#include <stdio.h>


// Asking for a positive integer
int get_positive_int(string prompt);

int main(void)

{
    int number = get_positive_int("Height: ");

    for (int height = 0; height < number; height++) //height and number of lines
    {
        for (int spaces = number - height - 2; spaces >= 0; spaces--) //to print spaces before pyramid
        {
            printf(" ");
        }
        for (int row = 0; row <= height; row++) //left pyramid
        {
            printf("#");
        }
        printf("  ");
        for (int row2 = 0; row2 <= height; row2++) //right pyramid
        {
            printf("#");
        }
        printf("\n");
    }
}

int get_positive_int(string prompt) //coding a function

{
    int number; //defining an integer
    do // do while loop to make an action
    {
        number = get_int("%s", prompt); //defining integer value, my BIGGEST value
    }
    while (number < 1 || number > 8); //checking the right range between 1 and 8
    return number; //returning if incorrect number
}