// Remove_Nth_Node_From_End_of_List.cpp: 定义控制台应用程序的入口点。
//
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

#include "stdafx.h"

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        if (nullptr == head)
        {
            return nullptr;
        }

        auto second = head;
        for (int i = 0; i <= n; ++i)
        {
            second = second->next;
            if (i < n && nullptr == second)
            {
                auto nth = head;
                head = head->next;
                delete nth;
                return head;
            }
        }

        auto first = head;
        while (second)
        {
            first = first->next;
            second = second->next;
        }

        auto nth = first->next;
        first->next = nth->next;
        delete nth;
        return head;
    }
};

int main()
{
    ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(2);
    ListNode* c = new ListNode(3);
    ListNode* d = new ListNode(4);
    ListNode* e = new ListNode(5);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;

    Solution sln;
    auto x = sln.removeNthFromEnd(e, 1);
    return 0;
}
