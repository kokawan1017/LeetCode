// Longest_Common_Prefix.cpp: 定义控制台应用程序的入口点。
//
// https://leetcode.com/problems/longest-common-prefix/

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <sstream>

class Solution
{
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs)
    {
        if (strs.empty())
        {
            return "";
        }

        std::string s1 = strs[0];
        bool done = false;
        size_t i = 0;
        for (; i != s1.length(); ++i)
        {
            std::string prefix = s1.substr(0, i + 1);
            for (size_t j = 1; j < strs.size(); ++j)
            {
                if (prefix != strs[j].substr(0, i + 1))
                {
                    done = true;
                }
            }

            if (done)
            {
                break;
            }
        }

        return s1.substr(0, i);
    }
};

int main()
{
    Solution sln;
    std::vector<std::string> v1 = { "flower", "flow", "flight" };
    std::cout << sln.longestCommonPrefix(v1) << std::endl;
    std::vector<std::string> v2 = { "dog","racecar","car" };
    std::cout << sln.longestCommonPrefix(v2) << std::endl;
    return 0;
}
