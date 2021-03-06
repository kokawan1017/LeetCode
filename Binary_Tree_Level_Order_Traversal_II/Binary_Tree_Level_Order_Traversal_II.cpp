// Binary_Tree_Level_Order_Traversal_II.cpp: 定义控制台应用程序的入口点。
//
// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <stack>

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
    std::vector<std::vector<int>> levelOrderBottom(TreeNode* root)
    {
        std::vector<std::vector<int>> orderedValues;
        travelByLevel(root, orderedValues, 0);
        std::reverse(orderedValues.begin(), orderedValues.end());
        return orderedValues;
    }
};

int main()
{
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    //root->right->left = new TreeNode(12);

    Solution sln;
    auto r = sln.levelOrderBottom(root);

    return 0;
}
