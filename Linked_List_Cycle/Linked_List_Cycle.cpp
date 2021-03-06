// Linked_List_Cycle.cpp : Defines the entry point for the console application.
// https://leetcode.com/problems/linked-list-cycle/

#include "stdafx.h"
#include <set>

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
    bool hasCycle(ListNode *head)
    {
        for (auto slower = head, faster = head; slower && faster; )
        {
            if (nullptr == slower->next || nullptr == faster->next || nullptr == faster->next->next)
            {
                return false;
            }

            slower = slower->next;
            faster = faster->next->next;
            if (slower == faster)
            {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    return 0;
}
