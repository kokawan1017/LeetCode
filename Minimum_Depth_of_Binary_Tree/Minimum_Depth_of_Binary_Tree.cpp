// Minimum_Depth_of_Binary_Tree.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

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
    int minDepth(TreeNode* root)
    {
        if (root)
        {
            if (nullptr == root->left && nullptr == root->right)
            {
                return 1;
            }

            int leftHeight = 1 + minDepth(root->left);
            int rightHeight = 1 + minDepth(root->right);
            return leftHeight < rightHeight ? leftHeight : rightHeight;
        }

        return 0;
    }
};

int main()
{
    return 0;
}
