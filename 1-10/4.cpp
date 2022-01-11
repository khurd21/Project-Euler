/*
A palindromic number reads the same both ways. The largest palindrome made from
the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.
*/

#include <stdio.h>

int reverse_num(int num, int partial=0) {
    if (!num) return partial;
    return reverse_num((int)num/10, partial*10+num%10);
}

int largest_palindrome_of_len_3() {
    int n1 = 999;
    int n2 = 999;
    int max = -1;

    while (n1 > 99) {
        n2 = n1;
        while (n2 > 99) {
            int potential = n1 * n2;
            if ((potential) == reverse_num(potential)) {
                max = (potential > max) ? potential : max;
            }
            n2 -= 1; 
        }
        n1 -= 1;
    }
    return max;
}

int main() {
    printf("%d\n", largest_palindrome_of_len_3());
}