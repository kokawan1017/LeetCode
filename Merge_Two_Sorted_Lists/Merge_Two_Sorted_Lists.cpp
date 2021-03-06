// Merge_Two_Sorted_Lists.cpp: 定义控制台应用程序的入口点。
//
// https://leetcode.com/problems/merge-two-sorted-lists/

#include "stdafx.h"

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };

class Solution
{
public:
    ListNode * mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        if (nullptr == l1)
        {
            return l2;
        }

        if (nullptr == l2)
        {
            return l1;
        }

        ListNode* newHead = nullptr;
        ListNode* newTail = nullptr;
        while (l1 != nullptr && l2 != nullptr)
        {
            ListNode* next = nullptr;
            if (l1->val < l2->val)
            {
                next = l1;
                l1 = l1->next;
            }
            else
            {
                next = l2;
                l2 = l2->next;
            }

            if (newHead)
            {
                newTail->next = next;
                newTail = next;
                newTail->next = nullptr;
            }
            else
            {
                newHead = next;
                newTail = newHead;
                newTail->next = nullptr;
            }
        }

        if (newTail)
        {
            if (l1 != nullptr)
            {
                newTail->next = l1;
            }
            else if (l2 != nullptr)
            {
                newTail->next = l2;
            }
        }
        return newHead;
    }
};

int main()
{
    return 0;
}
