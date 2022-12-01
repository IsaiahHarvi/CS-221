// sum digits using bitwise operators.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
int sumDigits(int num) {
    int d;
    int m;

    if ((num - 10) & 0b10000000000000000000000000000000) {
        return num;
    }
    d = (num >> 1) + (num >> 2);
    d += d >> 4;
    d += d >> 8;
    d += d >> 16;
    d >>= 3;

    d += (((9 - (num - ((((d << 2) + d) << 1)))) & 0b10000000000000000000000000000000) >> 31);

    return (num - ((((d << 2) + d) << 1))) + sumDigits(d);
}

int main() {
    std::cout << sumDigits(123) << std::endl << sumDigits(456) << std::endl << sumDigits(10) << std::endl << sumDigits(11) << std::endl << sumDigits(1239103411);
}
