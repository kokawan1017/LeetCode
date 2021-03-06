// Length_of_Last_Word.cpp: 定义控制台应用程序的入口点。
//
// https://leetcode.com/problems/length-of-last-word/

#include "stdafx.h"
#include <iostream>
#include <string>

class Solution
{
public:
    int lengthOfLastWord(std::string s)
    {
        int len = 0;
        int tail = s.length() - 1;
        while (tail >= 0 && s[tail] == ' ')
        {
            tail--;
        }

        while (tail >= 0 && s[tail] != ' ')
        {
            len++;
            tail--;
        }

        return len;
    }
};

int main()
{
    Solution sln;
    std::cout << sln.lengthOfLastWord("a ") << std::endl;
    std::cout << sln.lengthOfLastWord("a ab") << std::endl;
    return 0;
}
