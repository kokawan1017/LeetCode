// Symmetric_Tree.cpp: 定义控制台应用程序的入口点。
//
// https://leetcode.com/problems/symmetric-tree/

#include "stdafx.h"

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution
{
    bool isSymmetricTree(TreeNode* p, TreeNode* q)
    {
        if (p == q)
        {
            return true;
        }

        if (p && q)
        {
            if (p->val == q->val)
            {
                return isSymmetricTree(p->left, q->right) && isSymmetricTree(p->right, q->left);
            }
        }

        return false;
    }

public:
    bool isSymmetric(TreeNode* root)
    {
        if (root)
        {
            return isSymmetricTree(root->left, root->right);
        }

        return true;
    }
};

int main()
{
    return 0;
}
