#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // I declare a string variable for the name and ask the user name
    string name = get_string("What's your name? ");
    // Now concatenate the name with the Hello word and print it in the output
    printf("Hello, %s\n", name);
}