// Plus_One.cpp: 定义控制台应用程序的入口点。
//
// https://leetcode.com/problems/plus-one/

#include "stdafx.h"
#include <vector>
#include <iostream>

class Solution
{
public:
    std::vector<int> plusOne(std::vector<int>& digits)
    {
        auto num = digits;
        num.back() += 1;
        decltype(num) result;
        int sum = 0;
        while (!num.empty())
        {
            sum += num.back();
            num.pop_back();
            if (sum >= 10)
            {
                result.push_back(sum % 10);
                sum /= 10;
            }
            else
            {
                result.push_back(sum);
                sum = 0;
                break;
            }
        }

        if (num.empty())
        {
            if (sum > 0)
            {
                result.push_back(sum);
            }
        }
        else
        {
            result.insert(result.end(), num.rbegin(), num.rend());
        }

        return { result.rbegin(), result.rend() };
    }

};

int main()
{
    Solution sln;

    std::vector<int> n = { 9,9 };
    auto r = sln.plusOne(n);

    return 0;
}
