/*
 * Surprisingly there are only three numbers that can be written as the sum of
 * fourth powers of their digits:
 * 
 * 1634 = 1^4 + 6^4 + 3^4 + 4^4
 * 8208 = 8^4 + 2^4 + 0^4 + 8^4
 * 9474 = 9^4 + 4^4 + 7^4 + 4^4
 * As 1 = 1^4 is not a sum it is not included.
 * 
 * The sum of these numbers is 1634 + 8208 + 9474 = 19316.
 * 
 * Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.
 */

#include <cstdint>
#include <cmath>
#include <iostream>
#include <limits>

#include <boost/timer/timer.hpp>
#include <omp.h>

using boost::timer::auto_cpu_timer;

std::uint32_t sum_of_numbers(std::uint32_t number, std::uint32_t power) {

    std::uint32_t sum{ 0 };
    while (number != 0) {
        const auto digit{ number % 10 };
        sum += static_cast<std::uint32_t>(std::pow(digit, power));
        number /= 10;
    }
    return sum;
}

int main()
{
    auto_cpu_timer t;

    std::uint32_t result{ 0 };
    const auto end{ std::numeric_limits<std::uint32_t>::max() >> 1 };

    #pragma omp parallel for reduction(+:result)
    for (std::uint32_t n = 2; n < end; ++n) {
        if (sum_of_numbers(n, 5) == n) {
            result += n;
        }
    }

    std::cout << result << '\n';
}
