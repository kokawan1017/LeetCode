// Valid_Parentheses.cpp: 定义控制台应用程序的入口点。
//
// https://leetcode.com/problems/valid-parentheses/

#include "stdafx.h"
#include <iostream>
#include <stack>

class Solution
{
public:
    bool isValid(std::string s)
    {
        std::stack<char> parentheses;
        for (const auto c : s)
        {
            if (c == '(' || c == '[' || c == '{')
            {
                parentheses.push(c);
                continue;
            }

            if (parentheses.empty())
            {
                return false;
            }

            if (c == ')' && parentheses.top() == '(')
            {
                parentheses.pop();
            }
            else if (c == ']' && parentheses.top() == '[')
            {
                parentheses.pop();
            }
            else if (c == '}' && parentheses.top() == '{')
            {
                parentheses.pop();
            }
            else
            {
                break;
            }
        }

        return parentheses.empty();
    }
};

int main()
{
    Solution sln;
    std::cout << std::boolalpha << sln.isValid("]") << std::endl;
    std::cout << std::boolalpha << sln.isValid("()") << std::endl;
    std::cout << std::boolalpha << sln.isValid("()[]{}") << std::endl;
    std::cout << std::boolalpha << sln.isValid("(]") << std::endl;
    std::cout << std::boolalpha << sln.isValid("([)]") << std::endl;
    std::cout << std::boolalpha << sln.isValid("{[]}") << std::endl;
    return 0;
}
