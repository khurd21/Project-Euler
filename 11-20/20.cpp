/*
n! means n × (n − 1) × ... × 3 × 2 × 1

For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!
*/

#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>

typedef boost::multiprecision::uint1024_t uint1024_t;

constexpr uint1024_t factorial(const uint64_t n, const uint1024_t ans=1) {
    if (n <= 1) {
        return ans;
    }
    return factorial(n-1, ans*n);
}

template <class integer>
uint16_t sum_of_digits(integer n) {
    uint16_t answer{0};
    while (n != 0) {
        const uint8_t digit{n%10};
        n /= 10;
        answer += digit;
    }
    return answer;
}


int main() {
    uint1024_t fac_100{factorial(100)};
    std::cout << "Factorial of 100: " << fac_100 << '\n'
        << "Sum of numbers: " << sum_of_digits(fac_100) << '\n';
    return EXIT_SUCCESS;
}