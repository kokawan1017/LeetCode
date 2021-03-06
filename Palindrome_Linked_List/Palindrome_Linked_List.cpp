// Palindrome_Linked_List.cpp : Defines the entry point for the console application.
// https://leetcode.com/problems/palindrome-linked-list/

#include "stdafx.h"

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL)
    {}
};

/*
 * 判断回文
 * 比如 1->2->3->2->1 返回true
 *
 * 尝试 O(n) time and O(1) space
 */
class Solution
{
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

public:
    bool isPalindrome(ListNode* head)
    {
        auto middle = middleNode(head);
        auto secondHead = reverseList(middle);
        for (auto p1 = head, p2 = secondHead; p1 && p2 && p1 != p2; p1 = p1->next, p2 = p2->next)
        {
            if (p1->val != p2->val)
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    return 0;
}
