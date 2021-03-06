// PowXn.cpp: 定义控制台应用程序的入口点。
//
// https://leetcode.com/problems/powx-n/

#include "stdafx.h"
#include <iostream>
#include <cmath>

class Solution
{
public:
    double myPow(double x, int n)
    {
        int flag = 1;
        if (x < 0 && n & 2)
        {
            flag = -1;
        }

        double r = 0;
        if (n == INT_MIN)
        {
            r = flag * Pows(abs(x), abs(n + 1))*abs(x);
        }
        else
        {
            r = flag * Pows(abs(x), abs(n));
        }

        return (n > 0 ? r : 1 / r);
    }

    double Pows(double x, int n)
    {
        if (n == 0)
            return 1;

        if (n == 1)
            return x;

        double a = Pows(x, n / 2);
        if (n & 1)
        {
            return a * a * x;
        }

        return a * a;
    }
};

double myPow(double x, int n)
{
    bool negative = n < 0;
    if (0 == x || 1 == x)
    {
        return x;
    }
    if (-1 == x)
    {
        return -x;
    }

    int64_t p = n;
    if (negative)
    {
        p = -p;
    }

    double power = 1;
    for (int64_t i = 0; i < p; ++i)
    {
        power *= x;
    }
    if (negative)
    {
        power = 1 / power;
    }
    return power;
}

int main()
{

    std::pow(1, 1);
    std::cout << myPow(0, 3) << std::endl;
    return 0;
}
