// Roman_to_Integer.cpp: 定义控制台应用程序的入口点。
//
// https://leetcode.com/problems/roman-to-integer/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <unordered_map>

class Solution
{
public:
    Solution()
    {
        singleNumbers_["I"] = 1;
        singleNumbers_["V"] = 5;
        singleNumbers_["X"] = 10;
        singleNumbers_["L"] = 50;
        singleNumbers_["C"] = 100;
        singleNumbers_["D"] = 500;
        singleNumbers_["M"] = 1000;

        subNumbers_["IV"] = 4;
        subNumbers_["IX"] = 9;
        subNumbers_["XL"] = 40;
        subNumbers_["XC"] = 90;
        subNumbers_["CD"] = 400;
        subNumbers_["CM"] = 900;
    }

    int romanToInt(std::string s)
    {
        int sum = 0;
        for (size_t i = 0; i < s.length(); )
        {
            std::string n = s.substr(i, 2);
            if (subNumbers_.count(n) > 0)
            {
                sum += subNumbers_[n];
                i += 2;
            }
            else
            {
                sum += singleNumbers_[s.substr(i, 1)];
                ++i;
            }
        }
        return sum;
    }

private:
    std::unordered_map<std::string, int> singleNumbers_;
    std::unordered_map<std::string, int> subNumbers_;
};

int main()
{
    Solution sln;
    std::cout << sln.romanToInt("III") << std::endl;
    std::cout << sln.romanToInt("IV") << std::endl;
    std::cout << sln.romanToInt("IX") << std::endl;
    std::cout << sln.romanToInt("LVIII") << std::endl;
    std::cout << sln.romanToInt("MCMXCIV") << std::endl;
    return 0;
}
