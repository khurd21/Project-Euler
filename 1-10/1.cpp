/*
 * If we list all the natural numbers below 10 that are multiples of 3 or 5,
 * we get 3, 5, 6 and 9. The sum of these multiples is 23.
 * 
 * Find the sum of all the multiples of 3 or 5 below 1000.
 */

#include <cstdlib>
#include <iostream>
#include <set>

#include <boost/timer/timer.hpp>
#include <omp.h>

using boost::timer::auto_cpu_timer;

std::uint32_t sum_of_multiples(const std::set<std::uint32_t>& multiples, const std::uint32_t max) {

    std::uint32_t result{ 0 };
    for (std::uint32_t i = 0; i < max; ++i) {
        if (i % 3 == 0 || i % 5 == 0) {
            result += i;
        }
    }

    return result;
}

int main() {
    auto_cpu_timer t;

    std::cout << sum_of_multiples({3, 5}, 1'000) << '\n';
}