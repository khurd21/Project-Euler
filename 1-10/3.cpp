/*
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143?
*/
#include <stdio.h>

unsigned long largest_prime_factor_of(unsigned long target) {
    int max = -1;

    while ((target&1) == 0) {
        target >>= 1;
        max = 2;
    }

    for (int i = 3; (i*i) < target; i+=2) {
        while ((target%i) == 0) {
            target /= i;
            max = i;
        }
    }

    return (target > 2) ? target : max;
}

int main() {
   const unsigned long answer{largest_prime_factor_of(600'851'475'143)};
   printf("%u\n", answer);
}