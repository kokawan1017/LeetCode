// Search_Insert_Position.cpp: 定义控制台应用程序的入口点。
//
// https://leetcode.com/problems/search-insert-position/

#include "stdafx.h"
#include <vector>
#include <iostream>

class Solution
{
public:
    // [first, last)
    int bInsert(std::vector<int>& nums, size_t first, size_t last, int target)
    {
        while (first < last)
        {
            size_t mid = (first + last) / 2;
            if (nums[mid] == target)
            {
                return static_cast<int>(mid);
            }

            if (nums[mid] > target)
            {
                last = mid;
            }
            else if (nums[mid] < target)
            {
                first = mid + 1;
            }
        }

        if (first == last)
        {
            return last;
        }

        if (nums[first] <= target)
        {
            return first;
        }

        return first + 1;
    }

    int searchInsert(std::vector<int>& nums, int target)
    {
        return bInsert(nums, 0, nums.size(), target);
    }
};

int main()
{
    Solution sln;
    {
        std::vector<int> A = { 1,3,5,6 };
        std::cout << sln.searchInsert(A, 5) << std::endl;
        std::cout << sln.searchInsert(A, 2) << std::endl;
        std::cout << sln.searchInsert(A, 7) << std::endl;
        std::cout << sln.searchInsert(A, 0) << std::endl;
    }
    return 0;
}
