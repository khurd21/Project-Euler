/*
Starting in the top left corner of a 2×2 grid,
and only being able to move to the right and down,
there are exactly 6 routes to the bottom right corner.

How many such routes are there through a 20×20 grid?
*/

#include <iostream>
#include <map>
#include <cmath>

#define luint long unsigned int

luint get_number_routes(const std::pair<luint, luint> target) {

    luint ans{1};
    for (int i=1; i < target.first + 1; ++i) {
        ans *= i + target.first;
        ans /= i;
    }
    return ans;
}

int main() {

    std::pair<luint, luint> target{std::pair<luint, luint>(20, 20)};
    std::pair<luint, luint> base{std::pair<luint, luint>(2,2)};
    std::cout << get_number_routes(base) << '\n';
    std::cout << get_number_routes(target) << '\n';
    return EXIT_SUCCESS;
}