#include <cs50.h>
#include <stdio.h>

float discount(float price);

int main(void)
{
    float regular = get_float("Regular price: ");
    float sale = discount(regular);
    printf("Sale price: %.2f\n", sale);
}

float discount(float price)
{
    return price * .85;
}