// Add_Binary.cpp: 定义控制台应用程序的入口点。
//
// https://leetcode.com/problems/add-binary/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>

class Solution
{
    int add(char a, char b)
    {
        int sum = (a - '0') + (b - '0');
        return sum;
    }

    char toChar(int n)
    {
        return '0' + n;
    }

    int toInt(char c)
    {
        return c - '0';
    }

public:
    std::string addBinary(std::string a, std::string b)
    {
        std::ostringstream buffer;
        auto ita = a.rbegin();
        auto itb = b.rbegin();
        int sum = 0;

        for (; ita != a.rend() && itb != b.rend(); ++ita, ++itb)
        {
            sum += add(*ita, *itb);
            if (sum >= 2)
            {
                buffer << toChar(sum % 2);
                sum /= 2;
            }
            else
            {
                buffer << toChar(sum);
                sum = 0;
            }
        }

        for (; ita != a.rend() ; ++ita)
        {
            sum += toInt(*ita);
            if (sum >= 2)
            {
                buffer << toChar(sum % 2);
                sum /= 2;
            }
            else
            {
                buffer << toChar(sum);
                sum = 0;
            }
        }

        for (; itb != b.rend(); ++itb)
        {
            sum += toInt(*itb);
            if (sum >= 2)
            {
                buffer << toChar(sum % 2);
                sum /= 2;
            }
            else
            {
                buffer << toChar(sum);
                sum = 0;
            }
        }

        if (sum > 0)
        {
            buffer << toChar(sum);
        }

        std::string result = buffer.str();
        return { result.rbegin(), result.rend() };
    }
};

int main()
{
    Solution sln;
    std::cout << sln.addBinary("1", "11") << std::endl;
    std::cout << sln.addBinary("1010", "1011") << std::endl;
    return 0;
}
