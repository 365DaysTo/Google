#include <stdio.h>
#include <cs50.h>
#include <math.h>

// MASTERCARD: 16-Digit #'s, Start with: 51, 52, 53, 54, or 55
// VISA: 13-16-Digit #'s, Start with: 4
// AMEX: 15-Digit #'s, Star with: 34 or 37

int main(void) {
    // Global variables
    int count = 0;
    long cc;
    long ccNUM;
    string card;

    // Prompt user
    do {
        cc = get_long("Enter credit card number: ");
    } while (cc < 0);

    ccNUM = cc;

    // Count cc length
    while (cc > 0) {
        cc = cc / 10;
        count++;
    }

    // Check if cc num length is valid
    if (count != 13 && count != 15 && count != 16) {
        printf("INVALID");
    }

    // Luhn's Algorithm
    // Looping variables for computation
    long digit;
    int oneD;
    int twoD;
    int checker;
    int multi;
    int sum1 = 0;
    int sum2 = 0;
    int result;

    // Iterate 1 through length of CC
    for (int i = 0; i < count; i++) {
        // Create factor
        long factor = pow(10, i);

        // Formulate first set of digits (2nd from last)
        if (i % 2 != 0 && count == 16) {
            digit = (ccNUM / factor) % 10;
            multi = digit * 2;

            if (multi > 9) {
               int num1 = multi%10;
               int num2 = multi/10;
               multi = num1 + num2;
            }
            sum1 += multi;

            if (i == count-1) {
                oneD = digit;
            }
        }
        else if (i % 2 != 0 && (count == 13 || count == 15)) {
            digit = (ccNUM / factor) % 10;
            multi = digit * 2;

            if (multi > 9) {
               int num1 = multi%10;
               int num2 = multi/10;
               multi = num1 + num2;
            }
            sum1 += multi;

            if (i == count-2) {
                twoD = digit;
            }
        }

        // Formulate second set of digits (First from last)
        if (i % 2 == 0 && count == 16) {
            digit = (ccNUM / factor) % 10;
            sum2 += digit;

            if (i==count-2) {
                twoD = digit;
            }
        }
        else if (i % 2 == 0 && (count == 13 || count == 15)) {
            digit = (ccNUM / factor) % 10;
            sum2 += digit;

            if (i==count-1) {
                oneD = digit;
            }
        }
        checker = oneD + twoD;
    }

    // Define which card type
    if (count == 16 && digit == 4) {
        card = "VISA";
    }
    else if ((count == 13 || count == 16) && (checker >= 6 && checker <= 10)) {
        card = "MASTERCARD";
    }
    else if (count == 15 && (checker == 7 || checker == 10)) {
        card = "AMEX";
    }
    else {
        card = "INVALID";
    }

    // Compute final sum
    result = sum1 + sum2;

    // Final verification
    if (result % 10 == 0) {
        printf("%s\n", card);
    }
    else {
        printf("INVALID\n");
    }
}
