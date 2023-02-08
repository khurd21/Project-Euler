/*
 * A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
 * 
 * a^2 + b^2 = c^2
 * For example, 32 + 42 = 9 + 16 = 25 = 52.
 * 
 * There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 * Find the product abc.
 */

#include <cmath>
#include <iostream>
#include <tuple>

#include <boost/timer/timer.hpp>

using boost::timer::auto_cpu_timer;

typedef std::tuple<std::uint32_t, std::uint32_t, std::uint32_t> tuple_uint;

tuple_uint pythagorean_triplet(const std::uint32_t target_sum) {

    for (std::uint32_t a{ 1 }; a <= target_sum / 3; ++a) {
        for (std::uint32_t b{ a + 1 }; b <= target_sum / 2; ++b) {
            const std::uint32_t c{ target_sum - a - b };
            if ( std::pow(a, 2) + std::pow(b, 2) == std::pow(c, 2)) {
                return { a, b, c };
            }
        }
    }
    return { 0, 0, 0 };
}

int main() {
    auto_cpu_timer t;

    const auto [ a, b, c ]{ pythagorean_triplet(1'000) };
    std::cout << a * b * c << '\n';
}