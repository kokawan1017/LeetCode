// Binary_Tree_Level_Order_Traversal.cpp: 定义控制台应用程序的入口点。
//
// https://leetcode.com/problems/binary-tree-level-order-traversal/

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
    void travelByLevel(TreeNode* node, std::vector<std::vector<int>>& values, int curDep)
    {
        if (node)
        {
            if (values.size() <= curDep)
            {
                values.push_back(std::vector<int>());
            }

            if (node->left)
            {
                travelByLevel(node->left, values, curDep + 1);
            }

            if (node->right)
            {
                travelByLevel(node->right, values, curDep + 1);
            }

            values[curDep].push_back(node->val);
        }
    }

public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root)
    {
        std::vector<std::vector<int>> orderedValues;
        travelByLevel(root, orderedValues, 0);
        return orderedValues;
    }
};

int main()
{
    return 0;
}
