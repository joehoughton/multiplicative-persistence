#include <iostream>
#include <math.h>

int main(void) {
    int number, numberOfDigits, multiplicativePersistence = 0;
    bool multiplicativePersistenceFound = false;

    printf("\nEnter a number: "); // e.g. 375
    scanf("%d", &number);

    while(!multiplicativePersistenceFound){
        numberOfDigits = floor(log10 (abs (number))) + 1; // e.g. 375 has 3 digits
        int digits[numberOfDigits]; // initialize array with the size of number of digits
        int counter = 0;

        while (number > 0) { // split integer up into pieces in an array e.g. 375 becomes [3,7,5]
            int digit = number % 10;
            digits[counter] = digit; // use the counter to store the digit at the next empty array index
            number /= 10;
            counter++;
        }

        int sum = 1; // calculate sum of digits in array // e.g. 3 * 7 * 5
        for(int i = 0; i < sizeof(digits)/sizeof(digits[0]); i++) { // sizeof(digits)/sizeof(digits[0]) returns the size of array
            sum *= digits[i];
        }

        multiplicativePersistence++; // increase the multiplicative persistence each time we multiply the numbers together

        int numberofDigitsInSum = floor(log10 (abs (sum))) + 1; // get number of digits in sum

        if(numberofDigitsInSum <= 1){ // multiplicative persistence found
            multiplicativePersistenceFound = true; // stop the outside while loop
        } else {
            number = sum; // multiplicative persistence not found, keep looking
        }
    }

    printf("\nThe multiplicative persistence is %d", multiplicativePersistence);
}