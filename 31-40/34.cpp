/*
145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145
.

Find the sum of all numbers which are equal to the sum of the factorial of their digits.

Note: As 1! = 1 and 2! = 2 are not sums they are not included.
*/

#include <iostream>
#include <cstdint>
#include <ranges>
#include <unordered_map>
#include <concepts>

#include <omp.h>

#include <boost/timer/timer.hpp>

namespace {
    template <typename T>
    concept arithmetic = std::integral<T>;

    using boost::timer::auto_cpu_timer;
}


template <typename T>
requires arithmetic<T>
T factorial(T number) {

    static std::unordered_map<T, T> factorial_map;

    if (factorial_map.contains(number)) {
        return factorial_map.at(number);
    }

    const T key{ number };
    T result = 1;

    while (number > 1) {
        result *= number;
        --number;
    }

    #pragma omp critical
    factorial_map.insert({key, result});

    return result;
}

template <typename T>
requires arithmetic<T>
T sum_factorials(T value) {

    static std::unordered_map<T, T> sum_factorial_map;

    if (sum_factorial_map.contains(value)) {
        return sum_factorial_map.at(value);
    }

    const T key{ value };
    T sum{};
    while (value > 0) {
        const T number{ value % 10 };
        sum += factorial(number);
        value /= 10;
    }

    #pragma omp critical
    sum_factorial_map.insert({key, sum});

    return sum;
}

template <typename T>
requires arithmetic<T>
T find_sum_all_particular_values(const T begin, const T end) {

    const auto_cpu_timer t;

    T sum{};

    #pragma omp parallel for
    for (T value = begin; value < end; ++value) {
        if (sum_factorials(value) == value) {
            #pragma omp atomic
            sum += value;
        }
    }

    return sum;
}


int main() {
    std::cout << "Sum: " << find_sum_all_particular_values(3, 1'000'000) << '\n';
}