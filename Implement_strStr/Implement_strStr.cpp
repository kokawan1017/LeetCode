// Implement_strStr.cpp: 定义控制台应用程序的入口点。
//
// https://leetcode.com/problems/implement-strstr/

#include "stdafx.h"
#include <string>

class Solution
{
public:
    int strStr(std::string haystack, std::string needle)
    {
        if (haystack.length() < needle.length())
        {
            return -1;
        }

        const size_t N = haystack.length() - needle.length() + 1;
        for (size_t i = 0; i < N; ++i)
        {

        }
    }
};

int main()
{
    return 0;
}
