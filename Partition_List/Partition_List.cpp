// Partition_List.cpp : Defines the entry point for the console application.
// https://leetcode.com/problems/partition-list/

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
    ListNode * partition(ListNode* head, int x)
    {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
    }
};

int main()
{
    return 0;
}
