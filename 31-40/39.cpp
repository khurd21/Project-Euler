/*
If p is the perimeter of a right angle triangle with integral length sides {a, b, c}, there are exactly three solutions for p = 120.

{20, 48, 52}, {24, 45, 51}, {30, 40, 50}

For which value of p <= 1000, is the number of solutions maximized?
*/

#include <iostream>
#include <unordered_set>
#include <tuple>

#include <boost/timer/timer.hpp>
#include <omp.h>

using boost::timer::auto_cpu_timer;

struct TupleHash {
    template <typename T1, typename T2, typename T3>
    std::size_t operator()(const std::tuple<T1, T2, T3>& tuple) const {
        const auto& hash1 = std::hash<T1>{}(std::get<0>(tuple));
        const auto& hash2 = std::hash<T2>{}(std::get<1>(tuple));
        const auto& hash3 = std::hash<T3>{}(std::get<2>(tuple));
        return hash1 ^ hash2 ^ hash3;
    }
};

std::unordered_set<std::tuple<int, int, int>, TupleHash> find_pythagorean_triplets(const int perimeter) {
    std::unordered_set<std::tuple<int, int, int>, TupleHash> result;

    for (int a = 1; a < perimeter; ++a) {
        for (int b = a; b < perimeter; ++b) {
            const int c = perimeter - a - b;
            if (a * a + b * b == c * c) {
                result.insert(std::make_tuple(a, b, c));
            }
        }
    }
    return result;
}

int find_perimeter_with_max_triplets(const int p_start, const int p_end) {
    auto_cpu_timer t;

    int max_count{};
    int max_perimeter{};

    for (int p = p_start; p <= p_end; ++p) {
        const auto triplets{ find_pythagorean_triplets(p) };
        if (triplets.size() > max_count) {
            max_count = triplets.size();
            max_perimeter = p;
        }
    }

    return max_perimeter;
}

int main() {
    const int max_perimeter{ find_perimeter_with_max_triplets(1, 1000) };
    std::cout << "Perimeter with the maximum number of Pythagorean triplets: " << max_perimeter << std::endl;
    return 0;
}