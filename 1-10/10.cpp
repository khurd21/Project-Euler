/*
 * The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 *
 * Find the sum of all the primes below two million.
 */

#include <cstdint>
#include <iostream>

#include <boost/multiprecision/cpp_int.hpp>
#include <boost/timer/timer.hpp>
#include <omp.h>

using boost::multiprecision::cpp_int;
using boost::timer::auto_cpu_timer;

bool is_prime(const std::uint32_t n) {

    std::uint32_t range{n};
    for (std::uint32_t i = 2; i < range; ++i) {
        if (n % i == 0) return false;
        range = n / i;
    }
    return true;
}

cpp_int sum_of_primes(const std::uint32_t max) {

    cpp_int sum{ -1 };

    #pragma omp parallel for reduction(+:sum)
    for (std::uint32_t i = 1; i < max; ++i) {
        if (is_prime(i) == true) {
            sum += i;
        }
    }
    return sum;
}

int main() {
    auto_cpu_timer t;
    std::cout << sum_of_primes(2'000'000) << '\n';
}