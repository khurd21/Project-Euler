/*
The sum of the squares of the first ten natural numbers is,

The square of the sum of the first ten natural numbers is,

Hence the difference between the sum of the squares of the first ten natural
numbers and the square of the sum is 

Find the difference between the sum of the squares of the first one hundred
natural numbers and the square of the sum.
*/

#include <stdio.h>

#define uint unsigned int

uint difference_sum_of_squares_square_of_sum(const uint n) {
    uint square_of_sums = ((n*(n+1)) >> 1) * ((n*(n+1)) >> 1);
    uint sum_of_squares = ((n*(n+1)) * (2*n + 1)) / 6;
    return square_of_sums - sum_of_squares;
}

int main() {
    const uint answer{difference_sum_of_squares_square_of_sum(100)};
    printf("%u\n", answer);
}