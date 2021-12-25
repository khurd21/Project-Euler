'''
2**15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 2**1000?

2**1 = 2
-> 2

2**2 = 4
-> 4
2**4 = 16
-> 1 + 6 = 7
2**5 = 32
-> 3 + 2 = 5
'''

from math import pow

def sum_digits(n):
    ans = 0
    while n > 0:
        ans += n % 10
        n //= 10
    return ans


def main():
    print(f'Sum of 2**15: {sum_digits(int(pow(2, 15)))}')
    print(f'Sum of 2**1000: {sum_digits(int(pow(2, 1000)))}')


if __name__ == '__main__':
    main()