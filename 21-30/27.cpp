/*
n^2 + n + 41

The formula will produce 40 primes for the consecutive integer values 0 <= n <= 39
However, when n = 40, 40^2 + 40 + 41 = 40(40+1)+41 is divisible by 41 and certainly
when n = 41, 41^2 + 41 + 41 is clearly divisible by 41.

The formula n^2 - 79n + 1601 was discovered, which produces 80 primes for the consecutive
values 0 <= n <= 79. The product of the coefficients, -79 and 1601, is -126479.

Considering the quadratics of the form:

n^2 + an + b, where |a| < 1000 and |b| <= 1000

where |n| is the modulus/absolute value of n.
ex. |11| = 11 and |-4| = 4

Find the product of the coefficients, a and b, for the quadratic expression that
produces the maximum number of primes for consecutive values of n, starting with n = 0.
*/

#include<iostream>
#include<algorithm>

#define uint unsigned int

bool is_prime(const uint n) {

    uint range{n};
    for (uint i = 2; i < range; ++i) {
        if (n % i == 0) return false;
        range = n / i;
    }
    return true;
}

int get_number_consecutive_primes(int a, int b) {
    int result{ 0 };
    while (true) {
        const int value{ result * result + a * result + b };
        if (is_prime(value) == false) {
            return result;
        }
        ++result;
    }
    return -1;
}

int product_of_max_primes() {
    int max_c{ 0 };
    int max_ab{ 0 };

    #pragma omp parallel for collapse(2)
    for (int a = -999; a < 1000; ++a) {
        for (int b = -1000; b < 1001; ++b) {
            const int c{ get_number_consecutive_primes(a,b) };
            if (c > max_c) {
                #pragma omp atomic write
                max_c = c;
                #pragma omp atomic write
                max_ab = a * b;
            }
        }
    }

    return max_ab;
}

int main() {
    const int ans{ product_of_max_primes() };
    std::cout << ans << '\n';
}