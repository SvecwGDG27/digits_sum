#include <stdio.h> 

/*
 Calculates and prints the sum of the digits of an integer entered by the user.
 This program prompts the user to enter a number and then uses a while loop
 to iteratively extract and sum the individual digits of that number.
 prints the Sum of digits
 */
 
int main() {
    int num, sum = 0, digit;
    printf("Enter a number: ");
    scanf("%d", &num);

    while(num != 0) {
        // 1. Extract the last digit: The modulo operator (%) gives the remainder when divided by 10.
        digit = num % 10;
        
        // 2. Add the extracted digit to the running sum
        sum += digit;
        
        // 3. Remove the last digit: Integer division (/) by 10 truncates the last digit.
        num /= 10;
    }

    printf("Sum of digits = %d\n", sum);
    return 0;
}
