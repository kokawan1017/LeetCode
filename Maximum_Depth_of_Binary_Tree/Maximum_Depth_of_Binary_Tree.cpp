// Maximum_Depth_of_Binary_Tree.cpp: 定义控制台应用程序的入口点。
//
// https://leetcode.com/problems/maximum-depth-of-binary-tree/

#include "stdafx.h"
#include <algorithm>

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
    int maxDepth(TreeNode* root, int curDepth)
    {
        int depth = curDepth;
        if (root)
        {
            depth += 1;
            int leftDepth = maxDepth(root->left, depth);
            int rightDepth = maxDepth(root->right, depth);
            depth = std::max(depth, std::max(leftDepth, rightDepth));
        }

        return depth;
    }

public:
    int maxDepth(TreeNode* root)
    {
        return maxDepth(root, 0);
    }
};

int main()
{
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sln;
    int d = sln.maxDepth(root);
    return 0;
}
