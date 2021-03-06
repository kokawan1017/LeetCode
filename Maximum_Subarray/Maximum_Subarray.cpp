// Maximum_Subarray.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>

class Solution
{
public:
    int maxSubArray(std::vector<int>& nums)
    {
        int maxSum = INT_MIN;
        int sum = 0;
        for (const auto n : nums)
        {
            sum += n;
            if (maxSum < sum)
            {
                maxSum = sum;
            }

            if (sum < 0)
            {
                sum = 0;
            }
        }
        return maxSum;
    }
};

int main()
{
    Solution sln;
    std::vector<int> A = { -2,1,-3,4,-1,2,1,-5,4 };
    std::cout << sln.maxSubArray(A) << std::endl;
    std::vector<int> B = { -1 };
    std::cout << sln.maxSubArray(B) << std::endl;
    return 0;
}
