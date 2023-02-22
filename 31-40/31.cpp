/*
 * In the United Kingdom the currency is made up of pound (£) and pence (p).
 * There are eight coins in general circulation:
 * 
 * 1p, 2p, 5p, 10p, 20p, 50p, £1 (100p), and £2 (200p).
 * 
 * It is possible to make £2 in the following way:
 * 
 * 1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p
 * 
 * How many different ways can £2 be made using any number of coins?
 */

/*

1: 100 * 1p
2: 50 * 2p
3: 50 * 1p + 25 * 2p


*/

#include <array>
#include <cstdint>

#include <boost/timer/timer.hpp>
#include <boost/multiprecision/cpp_int.hpp>

using boost::multiprecision::cpp_int;
using boost::timer::auto_cpu_timer;


const std::array<std::uint32_t, 8> coins{ 1, 2, 5, 10, 20, 50, 100, 200 };


std::uint32_t number_combinations(const std::uint32_t amount) {

    std::vector<int> combinations(amount + 1);
    combinations[0] = 1;

    for (const auto coin : coins) {
        for (auto number{ coin }; number <= amount; ++number) {
            combinations[number] += combinations[number - coin];
        }
    }

    return combinations[amount];
}

int main() {

    auto_cpu_timer t;

    std::cout << number_combinations(200) << '\n';
}