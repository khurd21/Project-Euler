/*
A permutation is an ordered arrangement of objects. For example, 3124 is one possible
permutation of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically
or alphabetically, we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:

012   021   102   120   201   210

What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <boost/timer/timer.hpp>

#define uint unsigned int


int main() {

    boost::timer::auto_cpu_timer t;	
	
    std::string digits{"0123456789"};
    const uint target{1'000'000};

    for (uint i=1; i < target; ++i) {
        std::next_permutation(digits.begin(), digits.end());
    }
    std::cout << digits << '\n';

    return EXIT_SUCCESS;
}
