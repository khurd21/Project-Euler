/*
A perfect number is a number for which the sum of its proper divisors is exactly equal to
the number. For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28,
which means that 28 is a perfect number.

A number n is called deficient if the sum of its proper divisors is less than n and it is
called abundant if this sum exceeds n.

As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can
be written as the sum of two abundant numbers is 24. By mathematical analysis, it can be
shown that all integers greater than 28123 can be written as the sum of two abundant numbers.
However, this upper limit cannot be reduced any further by analysis even though it is known
that the greatest number that cannot be expressed as the sum of two abundant numbers is
less than this limit.

Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
*/

#include <boost/timer/timer.hpp>
#include <iostream>
#include <set>
#include <omp.h>

typedef unsigned int uint;

template <typename integer_type>
uint d(const integer_type n) {

    uint sum{1};
    for (uint i = 2; i*i <= n; ++i) {
        if (n % i == 0) {
            sum += i;
            uint tmp{(uint)n / i};
            if (tmp != i) {
                sum += tmp;
            }
        }
    }
    return sum > n;
}

template <typename integer_type>
bool has_two_sum(const integer_type target, const std::set<integer_type>& v) {

    if (target > 28'123) {
        return true;
    }

    for (integer_type value : v) {
        if (value > target / 2) {
            return false;
        }

        integer_type tmp{target - value};
        if (v.find(tmp) != v.end()) {
            return true;
        }
    }

    return false;
}


int main() {

    boost::timer::auto_cpu_timer t; // Timer starts when constructed, ends when destructed.

    std::set<uint> abundants;
    for (uint i=1; i < 28'124; ++i) {
        if (d(i)) {
            abundants.insert(i);
        }
    }

    uint sum{0};

    #pragma omp parallel for reduction(+:sum)
    for (uint i=1; i < 28'124; ++i) {
        if (!has_two_sum(i, abundants)) {
            sum += i;
        }
    }
    printf("%u\n", sum);
}

