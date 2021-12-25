/* 
The following iterative sequence is defined for the set of positive integers:

n → n/2 (n is even)
n → 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:

13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1

It can be seen that this sequence (starting at 13 and finishing at 1)
contains 10 terms. Although it has not been proved yet (Collatz Problem),
it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.
*/

#include <iostream>
#include <vector>
#include <map>
#include <limits>
#include <omp.h>

#define STARTING_NUMBER_THRESHOLD 1'000'000
#define uint unsigned int
#define uint_pair(x, y) std::pair<uint, uint>(x, y)

void _generate_next_sequence(uint& n) {
    if (n&1) { // odd
        n = 3*n + 1;
    }
    else { // even
        n >>= 1;
    }
}


uint chain_size(uint n, std::map<uint, uint>& cache) {

    const uint original_n{n};
    uint num_sequences{0};

    while (n != 1) {
        if (cache.find(n) != cache.end()) {
            cache.insert(uint_pair(original_n, cache[n]+num_sequences));
            return cache[original_n];
        }
        _generate_next_sequence(n);
        ++num_sequences;
    }

    cache.insert(std::pair<uint, uint>(original_n, num_sequences));
    return num_sequences;
}


int main() {

    std::pair<uint, uint> max_chain{std::pair<uint, uint> (0,0)};
    std::map<uint, uint> cache;

    cache.insert(std::pair<uint, uint>(1,1));

    #pragma omp parallel for
    for (int i=2; i < STARTING_NUMBER_THRESHOLD; ++i) {
        const uint tmp{chain_size(i, cache)};
        if (tmp > max_chain.second) {
            max_chain = std::pair<uint, uint>(i, tmp);
        }
    }

    std::cout << "N-Value: " << max_chain.first << " Length chain: " << max_chain.second << '\n';
    return EXIT_SUCCESS;
}