/* 
 * Starting with the number 1 and moving to the right in a clockwise
 * direction a 5x5 spiral is formed as follows:
 * 
 * 21 22 23 24 25
 * 20  7  8  9 10
 * 19  6  1  2 11
 * 18  5  4  3 12
 * 17 16 15 14 13
 * 
 * It can be verified that the sum of the numbers on the diagonals
 * is 101.
 * 
 * What is the sum of the numbers on the diagonals in a 1001x1001
 * spiral formed in the same way?
*/

#include <iostream>
#include <boost/timer/timer.hpp>

using boost::timer::auto_cpu_timer;

unsigned int sum_of_diagonals(const unsigned int n_by_n) {

    unsigned int c{ 1 };
    unsigned int s{ 1 };
    unsigned int a{ 2 };
    unsigned int n{ 3 };

    while (n <= n_by_n) {

        for (int i{ 0 }; i < 4; ++i) {
            c += a;
            s += c;
        }

        a += 2;
        n += 2;
    }

    return s;
}

int main() {
    auto_cpu_timer t;

    // A test of an output we know
    std::cout << "Actual: " << sum_of_diagonals(5) << " | Expected: 101\n";

    // Finding 1'001 by 1'001 sum of diagonals
    const auto result{ sum_of_diagonals(1'001) };
    std::cout << result << '\n';
}