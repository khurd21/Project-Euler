/*
The Fibonacci sequence is defined by the recurrence relation:

Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.
Hence the first 12 terms will be:

F1 = 1
F2 = 1
F3 = 2
F4 = 3
F5 = 5
F6 = 8
F7 = 13
F8 = 21
F9 = 34
F10 = 55
F11 = 89
F12 = 144
The 12th term, F12, is the first term to contain three digits.

What is the index of the first term in the Fibonacci sequence to contain 1000 digits?
*/

#include <stdio.h>
#include <cmath>

#include <boost/timer/timer.hpp>

#define uint unsigned int
#define SQRT5 (double)2.2360679775


uint num_minimum_n_digits(const uint n) {

    if (n < 2) {
        return n;
    }

    auto phi{(1 + SQRT5) / 2};
    auto num{n + std::log10(5) / 2 - 1};
    auto den{std::log10(phi)};

    return std::ceil(num / den);
}


int main() {

    boost::timer::auto_cpu_timer t;

    uint ans{num_minimum_n_digits(1'000)};
    printf("%u\n", ans);
    return EXIT_SUCCESS;
}
