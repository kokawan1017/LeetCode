// TwoSum.cpp: 定义控制台应用程序的入口点。
//
// https://leetcode.com/problems/two-sum/

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <unordered_map>

std::vector<int> twoSum(std::vector<int>& nums, int target)
{
    int first = 0;
    int second = 1;
    while (true)
    {
        if (nums[first] + nums[second] == target)
        {
            break;
        }
        else
        {
            if (second == nums.size() - 1)
            {
                ++first;
                second = first + 1;
            }
            else
            {
                ++second;
            }
        }
    }

    std::vector<int> result;
    result.push_back(first);
    result.push_back(second);
    return result;
}

std::vector<int> twoSum_HASH(std::vector<int>& nums, int target)
{
    std::unordered_map<int, int> tmp;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (tmp.count(target - nums[i])) // tmp中找到一个值使得 key + nums[i] == target
        {
            return { tmp[target - nums[i]], i };
        }

        tmp[nums[i]] = i;
    }
    return { (int)nums.size(), (int)nums.size() };
}

void test1()
{
    std::vector<int> nums = { 0, 1, 2,3,4,5,6,7,11,15 };
    int target = 9;

    std::vector<int> result = twoSum(nums, target);
}

void test2()
{
    std::vector<int> nums = { 1,2,3,3,7 };
    int target = 6;

    std::vector<int> result = twoSum(nums, target);
}

void test3()
{
    std::vector<int> nums = { 3,2,4 };
    int target = 6;

    std::vector<int> result = twoSum(nums, target);
}

int main()
{
    test1();
    test2();
    test3();
    return 0;
}
