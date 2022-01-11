/*
Each new term in the Fibonacci sequence is generated by adding the previous two
terms. By starting with 1 and 2, the first 10 terms will be:

1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...

By considering the terms in the Fibonacci sequence whose values do not exceed
four million, find the sum of the even-valued terms.
*/

#include <stdio.h>

#define uint unsigned int

static uint sum{0};

uint even_fib_to(const int target, uint prev=1, uint curr=2) {
    sum += !(curr&1) * curr;
    {
        uint tmp{curr};
        curr = prev + curr;
        prev = tmp;
    }
    return (curr > target) ? sum : even_fib_to(target, prev, curr);   
}

int main() {
    const uint answer{even_fib_to(4'000'000)};
    printf("%u\n", answer);
}