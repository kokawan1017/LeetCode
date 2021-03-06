// ReverseInteger.cpp: 定义控制台应用程序的入口点。
//
// https://leetcode.com/problems/reverse-integer/

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <sstream>

int power(int x, int m)
{
    int s = 1;
    for (int i = 0; i < m; ++i)
    {
        s *= x;
    }
    return s;
}

int reverse_2(int x)
{
    if (0 == x)
    {
        return 0;
    }

    bool negative = (x < 0);
    if (negative)
    {
        x = -x;
    }

    std::vector<int> number;
    while (x > 0)
    {
        number.push_back(x % 10);
        x /= 10;
    }

    int n = 0;
    size_t size = number.size();
    for (size_t i = 0; i != size; ++i)
    {
        n += (number[i] * power(10, size - i - 1));
    }

    if (negative)
    {
        n = -n;
    }
    return n;
}

int reverse_1(int x)
{
    int64_t n = 0;
    while (x != 0)
    {
        n = n * 10 + x % 10;
        x /= 10;
    }

    if (n > INT32_MAX || n < INT32_MIN)
        return 0;

    return (int)n;
}

#define reverse reverse_1

int main()
{
    std::cout << reverse(-123) << std::endl;
    std::cout << reverse(123) << std::endl;
    std::cout << reverse(0) << std::endl;
    std::cout << reverse(120) << std::endl;
    std::cout << reverse(1201) << std::endl;

    return 0;
}
