// Delete_Node_in_a_Linked_List.cpp : Defines the entry point for the console application.
// https://leetcode.com/problems/delete-node-in-a-linked-list

#include "stdafx.h"

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL)
    {}
};

class Solution
{
public:
    void deleteNode(ListNode* node)
    {
        node->val = node->next->val;
        auto target = node->next;
        node->next = node->next->next;
        delete target;
    }
};

int main()
{
    return 0;
}
