// Balanced_Binary_Tree.cpp: 定义控制台应用程序的入口点。
//
// https://leetcode.com/problems/balanced-binary-tree/

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
    int height(TreeNode* root)
    {
        if (root)
        {
            int leftHeight = 1+ height(root->left);
            int rightHeight = 1 + height(root->right);
            return leftHeight > rightHeight ? leftHeight : rightHeight;
        }

        return 0;
    }

public:
    bool isBalanced(TreeNode* root)
    {
        if (root)
        {
            int leftHeight = height(root->left);
            int rightHeight = height(root->right);
            if (std::abs(leftHeight - rightHeight) <= 1)
            {
                return isBalanced(root->left) && isBalanced(root->right);
            }

            return false;
        }

        return true;
    }
};

int main()
{
    auto a = new TreeNode(1);
    auto b1 = new TreeNode(2);
    auto b2 = new TreeNode(2);
    auto c1 = new TreeNode(3);
    auto c2 = new TreeNode(3);
    auto d1 = new TreeNode(4);
    auto d2 = new TreeNode(4);
    a->left = b1;
    a->right = b2;
    b1->left = c1;
    b1->right = c2;
    c1->left = d1;
    c1->right = d2;

    bool r = Solution().isBalanced(a);
    return 0;
}
