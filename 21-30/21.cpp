/*
Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.

For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284.
The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

Evaluate the sum of all the amicable numbers under 10000.
*/

#include <iostream>
#include <vector>
#include <limits>
#include <omp.h>

static unsigned int UINT_MAX {std::numeric_limits<unsigned int>::max()};
static unsigned int NUM_ELEMENTS {10'000};

typedef unsigned int uint;

static std::vector<uint> proper_divisors(NUM_ELEMENTS, UINT_MAX);


template <typename integer_type>
uint d(const integer_type n) {

    uint sum{0};
    for (uint i = 1; i < n; ++i) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum;
}


int main() {

    #pragma omp parallel for
    for (uint i=1; i < NUM_ELEMENTS; ++i) {
        proper_divisors[i] = d(i);
    }

    uint sum{0};
    #pragma omp parallel for schedule(dynamic) reduction(+:sum)
    for (uint i=1; i < NUM_ELEMENTS; ++i) {
        if (i == proper_divisors[proper_divisors[i]] && i != proper_divisors[i]) {
            printf("%u -> %u\n", i, proper_divisors[i]);
            sum += i;
        }
    }

    printf("Sum of all amicable numbers under %u: %u\n", NUM_ELEMENTS, sum);
    return EXIT_SUCCESS;
}