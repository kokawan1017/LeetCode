// Remove_Duplicates_from_Sorted_List_II.cpp : Defines the entry point for the console application.
// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

#include "stdafx.h"

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x, ListNode* n = nullptr) : val(x), next(n)
    {}
};

class Solution
{
public:
    ListNode * deleteDuplicates(ListNode* head)
    {
        auto preHead = new ListNode(0);
        preHead->next = head;
        bool duplicated = false;
        for (auto node = preHead; node->next; )
        {
            if (node->next->next && node->next->val == node->next->next->val)
            {
                duplicated = true;
                auto target = node->next->next;
                node->next->next = target->next;
                delete target;
            }
            else
            {
                if (duplicated)
                {
                    auto target = node->next;
                    node->next = target->next;
                    delete target;
                }
                else
                {
                    node = node->next;
                }

                duplicated = false;
            }
        }

        head = preHead->next;
        delete preHead;
        return head;
    }
};

int main()
{
    Solution sln;
    ListNode* head = new ListNode(1, new ListNode(1, new ListNode(3, new ListNode(4, new ListNode(4)))));
    auto newHead = sln.deleteDuplicates(head);

    return 0;
}
