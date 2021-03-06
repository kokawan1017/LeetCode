// LongestSubstringWithoutRepeatingCharacters.cpp: 定义控制台应用程序的入口点。
//
// https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <unordered_map>

int lengthOfLongestSubstring(std::string s)
{
    size_t first = 0;
    size_t last = s.size();
    size_t maxWindow = 0;
    std::unordered_map<char, size_t> subset;
    while (first < last)
    {
        bool hasDuplicated = false;
        size_t window = 0;
        for (size_t i = first; i != last; ++i)
        {
            if (subset.count(s[i]) > 0)
            {
                hasDuplicated = true;
                first = subset[s[i]] + 1;
                break;
            }

            ++window;
            subset[s[i]] = i;
        }

        if (maxWindow < window)
        {
            maxWindow = window;
        }

        if (!hasDuplicated)
        {
            ++first;
        }

        if (last - first < maxWindow)
        {
            break;
        }

        subset.clear();
    }

    return static_cast<int>(maxWindow);
}

int main()
{
    std::cout << lengthOfLongestSubstring("abcabcbb") << std::endl;
    std::cout << lengthOfLongestSubstring("bbbbb") << std::endl;
    std::cout << lengthOfLongestSubstring("pwwkew") << std::endl;
    std::cout << lengthOfLongestSubstring("ab") << std::endl;
    std::cout << lengthOfLongestSubstring("") << std::endl;
    std::cout << lengthOfLongestSubstring("xxzqi") << std::endl;
    return 0;
}
