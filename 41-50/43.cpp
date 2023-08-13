/*
The number, 1406357289, is a 0-9 pandigital number because it is made up of each of the digits 0-9 in some order,
but it also has a rather interesting sub-string divisibility property.

Let d1 be the first digit, d2 be the second digit, and so on. In this way, we note the following:

- d2d3d4 = 406 is divisible by 2.
- d3d4d5 = 063 is divisible by 3.
- d4d5d6 = 635 is divisible by 5.
- d5d6d7 = 357 is divisible by 7.
- d6d7d8 = 572 is divisible by 11.
- d7d8d9 = 728 is divisible by 13.
- d8d9d10 = 289 is divisible by 17.

Find the sum of all 0-9 pandigital numbers with this property.
*/

/*
- Length of string must be 10.


- Find all numbers of length 3 that are divisible by 2, 3, 5, 7, 11, 13, 17
*/

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>

#include <boost/multiprecision/cpp_int.hpp>
#include <boost/timer/timer.hpp>
#include <omp.h>

using boost::multiprecision::cpp_int;
using boost::timer::auto_cpu_timer;


constexpr bool is_special(const std::string& pandigital) {
    const std::vector<int> primes{ 2, 3, 5, 7, 11, 13, 17 };
    for (int i = 0; i < 7; ++i) {
        const std::string substring{ pandigital.substr(i + 1, 3) };
        if (std::stoi(substring) % primes[i] != 0) {
            return false;
        }
    }
    return true;
}

template <typename T>
constexpr T sum_special_pandigital_numbers() {
    std::string pandigital{ "0123456789" };
    T result{};
    do {
        if (is_special(pandigital) == true) {
            result += std::stoul(pandigital);
        }
    } while (std::next_permutation(pandigital.begin(), pandigital.end()));
    return result;
}


int main() {
    auto_cpu_timer t;
    cpp_int result{ sum_special_pandigital_numbers<cpp_int>() };
    std::cout << "Sum: " << result << '\n';
}