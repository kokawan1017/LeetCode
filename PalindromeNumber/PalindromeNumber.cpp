// PalindromeNumber.cpp: 定义控制台应用程序的入口点。
//
// https://leetcode.com/problems/palindrome-number/

#include "stdafx.h"
#include <iostream>
#include <string>

bool isPalindrome(int x)
{
    if (x < 0 || (x % 10 == 0 && x != 0))
    {
        return false;
    }

    int revertedNumber = 0;
    while (x > revertedNumber)
    {
        revertedNumber = revertedNumber * 10 + x % 10;
        x /= 10;
    }

    return x == revertedNumber || x == revertedNumber / 10;
}

int main()
{
    std::cout << std::boolalpha << isPalindrome(0) << std::endl;
    std::cout << std::boolalpha << isPalindrome(12) << std::endl;
    std::cout << std::boolalpha << isPalindrome(12321) << std::endl;
    std::cout << std::boolalpha << isPalindrome(-121) << std::endl;
    return 0;
}
