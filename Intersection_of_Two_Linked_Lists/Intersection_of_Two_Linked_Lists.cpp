// Intersection_of_Two_Linked_Lists.cpp : Defines the entry point for the console application.
// https://leetcode.com/problems/intersection-of-two-linked-lists/

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
    ListNode * getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        for (auto nodeA = headA, nodeB = headB; nodeA && nodeB; )
        {

        }
    }
};

int main()
{
    return 0;
}
