// Middle_of_the_Linked_List.cpp : Defines the entry point for the console application.
// https://leetcode.com/problems/middle-of-the-linked-list/

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
    ListNode * middleNode(ListNode* head)
    {
        ListNode* slower = head;
        ListNode* faster = head;
        while (slower && faster && faster->next)
        {
            slower = slower->next;
            faster = faster->next->next;
        }

        return slower;
    }
};

int main()
{
    return 0;
}
