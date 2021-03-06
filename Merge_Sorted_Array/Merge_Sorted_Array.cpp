// Merge_Sorted_Array.cpp: 定义控制台应用程序的入口点。
//
// https://leetcode.com/problems/merge-sorted-array/

#include "stdafx.h"
#include <vector>

class Solution
{
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)
    {
        for (int i = 0; i < n; ++i)
        {
            nums1[m + i] = nums2[i];
        }

        for (int i = m; i < m + n; ++i)
        {
            int flag = nums1[i];
            int j = i;
            for (; j > 0; --j)
            {
                if (nums1[j - 1] > flag)
                {
                    nums1[j] = nums1[j - 1];
                }
                else
                {
                    break;
                }
            }

            nums1[j] = flag;
        }
    }
};

int main()
{
    Solution sln;
    std::vector<int> v1 = { 1,2,3 };
    int m = v1.size();
    std::vector<int> v2 = { 2,5,6 };
    int n = v2.size();
    v1.resize(v1.size() + v2.size());
    sln.merge(v1, m, v2, n);
    return 0;
}
