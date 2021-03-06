// AddTwoNumbers.cpp: 定义控制台应用程序的入口点。
//
// https://leetcode.com/problems/add-two-numbers/

#include "stdafx.h"

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL)
    {}
};

void appendList(ListNode*& head, ListNode*& last, int val)
{
    ListNode* result = new ListNode(val);
    if (head)
    {
        last->next = result;
        last = result;
    }
    else
    {
        head = result;
        last = head;
    }
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode* head = NULL;
    ListNode* last = NULL;

    ListNode* n1 = l1;
    ListNode* n2 = l2;

    int forward = 0;
    for (; n1 != NULL && n2 != NULL; n1 = n1->next, n2 = n2->next)
    {
        int sum = n1->val + n2->val + forward;
        forward = sum / 10; // 进位

        appendList(head, last, sum % 10);
    }

    if (n1 || n2)
    {
        ListNode* rest = n1 ? n1 : n2;
        for (ListNode* p = rest; p; p = p->next)
        {
            int sum = forward + p->val;
            forward = sum / 10; // 进位

            appendList(head, last, sum % 10);
        }
    }

    if (forward > 0)
    {
        appendList(head, last, forward);
    }

    return head;
}

int main()
{
    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(9);
    l2->next = new ListNode(9);

    ListNode* result = addTwoNumbers(l1, l2);
    return 0;
}
