/* We shall say that an n-digit number is pandigital if it makes use of all the
 * digits 1 to n exactly once; for example, the 5-digit number, 15234, is 1
 * through 5 pandigital.
 * 
 * The product 7254 is unusual, as the identity, 39 × 186 = 7254, containing
 * multiplicand, multiplier, and product is 1 through 9 pandigital.
 * 
 * Find the sum of all products whose multiplicand/multiplier/product identity
 * can be written as a 1 through 9 pandigital.
 * 
 * HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.
 */

#include <set>
#include <iostream>

#include <boost/multiprecision/cpp_int.hpp>
#include <boost/timer/timer.hpp>

#include <omp.h>

using boost::timer::auto_cpu_timer;
using boost::multiprecision::cpp_int;


bool is_pandigital(const int multiplicand, const int multiplier) {

    std::set<int> found_numbers;
    const int product{ multiplicand * multiplier };

    auto pandigital_appender = [&found_numbers](int number) -> bool {

        while (number > 0) {
            const auto value{ number % 10 };
            if (value == 0) {
                return false;
            }
            else if (found_numbers.find(value) != found_numbers.end()) {
                return false;
            }
            else {
                found_numbers.insert(value);
            }
            number /= 10;
        }
        return true;
    };

    bool result{ true };
    result &= pandigital_appender(multiplicand);
    result &= pandigital_appender(multiplier);
    result &= pandigital_appender(product);

    return result && found_numbers.size() == 9;
}

int sum_products_of_pandigital_mmp() {

    std::set<int> products;

    #pragma omp parallel for collapse(2)
    for (int multiplicand = 1; multiplicand < 1'000; ++multiplicand) {
        for (int multiplier = multiplicand + 1; multiplier < 2'000; ++multiplier) {
            if (is_pandigital(multiplicand, multiplier)) {
                #pragma omp critical
                {
                    products.insert(multiplicand * multiplier);
                }
            }
        }
    }

    return std::accumulate(products.begin(), products.end(), 0);
}

int main() {

    auto_cpu_timer t;

    std::cout << sum_products_of_pandigital_mmp() << '\n';
}