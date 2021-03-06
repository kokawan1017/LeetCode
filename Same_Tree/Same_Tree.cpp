// Same_Tree.cpp: 定义控制台应用程序的入口点。
//
// https://leetcode.com/problems/same-tree/

#include "stdafx.h"
#include <xutility>

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
public:
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        if (p == q)
        {
            return true;
        }

        if (p && q)
        {
            if (p->val == q->val)
            {
                return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
            }
        }

        return false;
    }
};

int main()
{
    return 0;
}
