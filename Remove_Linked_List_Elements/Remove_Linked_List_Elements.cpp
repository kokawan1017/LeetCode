// Remove_Linked_List_Elements.cpp : Defines the entry point for the console application.
// https://leetcode.com/problems/remove-linked-list-elements/

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
    ListNode * removeElements(ListNode* head, int val)
    {
        while (head && head->val == val)
        {
            auto target = head;
            head = head->next;
            delete target;
        }

        for (auto node = head; node && node->next; )
        {
            if (node->next->val == val)
            {
                auto target = node->next;
                node->next = target->next;
                delete target;
            }
            else
            {
                node = node->next;
            }
        }

        return head;
    }
};

int main()
{
    return 0;
}
