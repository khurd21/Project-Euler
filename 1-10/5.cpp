/*

2520 is the smallest number that can be divided by each of the numbers from
1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the
numbers from 1 to 20?
*/

#include <stdio.h>

#define uint unsigned int


uint smallest_num_evenly_divisible_1to(const uint n) {
    uint target = (n-1)<<1;
    while (true) {
        bool flag = true;
        for (int i=2; i <= n; ++i) {
            if (target % i != 0) {
                target += 2;
                flag = false;
                break;
            }
        }
        if (flag) return target;
    }
}

int main() {
    const uint answer{smallest_num_evenly_divisible_1to(20)};
    printf("%u\n", answer);
}