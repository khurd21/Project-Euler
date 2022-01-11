/*
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see
that the 6th prime is 13.

What is the 10 001st prime number?
*/

#include <stdio.h>

#define uint unsigned int



bool is_prime(const uint n) {

    uint range{n};
    for (uint i = 2; i < range; ++i) {
        if (n % i == 0) return false;
        range = n / i;
    }
    return true;
}

int main() {
    uint num_primes{0};
    uint i{1};

    for (i = 1; i > 0 && num_primes <= 10'001; ++i) {
        num_primes += is_prime(i);
    }
    printf("Num Primes: %u\n", num_primes-1);
    printf("Prime Num:  %u\n", i-1);
}