/*
If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are
3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words,
how many letters would be used?


NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23
letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and"
when writing out numbers is in compliance with British usage.

342     - three hundred and forty two
4342    - four thousand three hundred and forty two
54342   - fifty four thousand three hundred and forty two

zero (0) is exluded in this example
*/

#include <stdio.h>
#define uint unsigned int

constexpr static uint zero_to_nineteen[] = {0, 3, 3, 5, 4, 4, 3, 5, 5, 4, 3, 6, 6, 8, 8, 7, 7, 9, 8, 8};
constexpr static uint tenths[]           = {6, 6, 5, 5, 5, 7, 6, 6};


constexpr uint calculate_hundreds(const uint n) {
    return (n < 20) ?
            zero_to_nineteen[n] :
            tenths[(uint) n / 10 - 2 | 0] + zero_to_nineteen[n % 10];
}

uint length(const uint n) {

    if (n < 100) {
        return calculate_hundreds(n);
    }

    uint length{0};
    uint tens{n % 100};
    uint hundreds{(uint)(n / 100) % 10};
    uint thousands{(uint)(n / 1000)};

    if (n > 999) {
        length += calculate_hundreds(thousands) + 8;
    }
    if (hundreds != 0) {
        length += zero_to_nineteen[hundreds] + 7;
    }
    if (tens != 0) {
        length += calculate_hundreds(tens) + 3;
    }
    return length;
}

int main() {

    uint result{0};
    for (int i=1; i < 1001; ++i) {
        result += length(i);
    }
    printf("%u\n", result);
    return 0;
}