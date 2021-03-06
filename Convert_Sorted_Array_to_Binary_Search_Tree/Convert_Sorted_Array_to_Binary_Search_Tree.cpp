// Convert_Sorted_Array_to_Binary_Search_Tree.cpp: 定义控制台应用程序的入口点。
//
// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

#include "stdafx.h"
#include <vector>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL)
    {}
};

class Solution
{
    TreeNode* arrayToBst(std::vector<int>::iterator first, std::vector<int>::iterator last)
    {
        if (first == last)
        {
            return nullptr;
        }

        int mid = std::distance(first, last) / 2;
        auto root = new TreeNode(*(first + mid));
        root->left = arrayToBst(first, first + mid);
        root->right = arrayToBst(first + mid + 1, last);
        return root;
    }

public:
    TreeNode * sortedArrayToBST(std::vector<int>& nums)
    {
        return arrayToBst(std::begin(nums), std::end(nums));
    }
};

int main()
{
    std::vector<int> v = { -10,-3,0,5,9 };
    auto root = Solution().sortedArrayToBST(v);

    std::vector<int> v2 = { 0,1,2,3,4,5 };
    auto root2 = Solution().sortedArrayToBST(v2);
    return 0;
}
