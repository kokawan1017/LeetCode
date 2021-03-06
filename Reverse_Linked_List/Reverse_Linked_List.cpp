// Reverse_Linked_List.cpp : Defines the entry point for the console application.
// https://leetcode.com/problems/reverse-linked-list/

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
    ListNode * reverseList(ListNode* head)
    {
        ListNode* newHead = nullptr;
        for (auto node = head; node; )
        {
            auto next = node->next;
            node->next = newHead;
            newHead = node;
            node = next;
        }
        return newHead;
    }
};

int main()
{
    return 0;
}
