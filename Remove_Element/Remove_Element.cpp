// Remove_Element.cpp: 定义控制台应用程序的入口点。
//
// https://leetcode.com/problems/remove-element/submissions/

#include "stdafx.h"
#include <iostream>
#include <vector>

class Solution
{
public:
    int removeElement(std::vector<int>& nums, int val)
    {
        size_t index = 0;
        for (size_t i = 0; i < nums.size(); ++i)
        {
            if (nums[i] != val)
            {
                nums[index++] = nums[i];
            }
        }
        nums.resize(index);
        return nums.size();
    }
};

int main()
{
    return 0;
}
