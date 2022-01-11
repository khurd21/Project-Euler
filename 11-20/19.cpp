/*
You are given the following information, but you may prefer to do some research for yourself.

1 Jan 1900 was a Monday.

Thirty days has September,
April, June and November.

All the rest have thirty-one,
Saving February alone,
Which has twenty-eight, rain or shine.
And on leap years, twenty-nine.

A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?

Jan - 31
Feb - 28 (leap yr. 29)
Mar - 31
Apr - 30
May - 31
Jun - 30
Jul - 31
Aug - 31
Sep - 30
Oct - 31
Nov - 30
Dec - 31

leap year = (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0)

We know - 1 Jan 1901 is a Tuesday.
*/
#include <cstdint>
#include <stdio.h>

int main() {
    const uint16_t start_year{1901};
    const uint16_t end_year{2000};
    const uint32_t num_months{ (end_year-start_year+1) * 12};

    // assuming even distribution
    const uint32_t num_sundays{ (uint32_t) num_months * 1/7 };
    printf("%u\n", num_sundays);
    return 0;
}