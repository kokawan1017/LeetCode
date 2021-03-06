// Remove_Duplicates_from_Sorted_Array.cpp: 定义控制台应用程序的入口点。
//
// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

#include "stdafx.h"
#include <iostream>
#include <vector>

class Solution
{
public:
    int removeDuplicates(std::vector<int>& nums)
    {
        if (nums.empty() || nums.size() == 1)
        {
            return nums.size();
        }

        size_t index = 1; // 插入点
        for (size_t i = 0; i < nums.size(); )
        {
            int flag = nums[i];

            bool found = false;
            size_t j = i + 1;
            for (; j< nums.size(); ++j)
            {
                if (nums[j] != nums[i])
                {
                    found = true;
                    nums[index++] = nums[j];
                    i = j;
                    break;
                }
            }

            if (!found)
            {
                break;
            }
        }

        nums.resize(index);
        return static_cast<int>(nums.size());
    }
};

void print(const std::vector<int>& nums)
{
    std::cout << "[" << nums.size() << "] [";
    for (size_t i = 0; i < nums.size(); ++i)
    {
        std::cout << nums[i];
        if (i != nums.size() - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

int main()
{
    Solution sln;
    {
        std::vector<int> v1;
        print(v1);
        sln.removeDuplicates(v1);
        print(v1);
    }

    {
        std::vector<int> v1 = { 1,2,3 };
        print(v1);
        sln.removeDuplicates(v1);
        print(v1);
    }

    {
        std::vector<int> v1 = { 1,2,2,3,3,3 };
        print(v1);
        sln.removeDuplicates(v1);
        print(v1);
    }

    {
        std::vector<int> v1 = { 1,1,1,2,2,3,3,3 };
        print(v1);
        sln.removeDuplicates(v1);
        print(v1);
    }

    {
        std::vector<int> v1 = { 1 };
        print(v1);
        sln.removeDuplicates(v1);
        print(v1);
    }
    return 0;
}
