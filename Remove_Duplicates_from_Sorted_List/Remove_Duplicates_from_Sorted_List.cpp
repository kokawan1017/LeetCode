// Remove_Duplicates_from_Sorted_List.cpp: 定义控制台应用程序的入口点。
//
// https://leetcode.com/problems/remove-duplicates-from-sorted-list/

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
        if (head)
        {
            int lastVal = head->val;
            for (auto node = head; node; )
            {
                if (node->next)
                {
                    if (lastVal == node->next->val)
                    {
                        auto p = node->next;
                        node->next = p->next;
                        delete p;
                        continue;
                    }

                    lastVal = node->next->val;
                }

                node = node->next;
            }
        }

        return head;
    }
};

int main()
{
    Solution sln;
    ListNode* h1 = new ListNode(1, new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(3)))));
    auto r1 = sln.deleteDuplicates(h1);

    auto h2 = new ListNode(1);
    auto r2 = sln.deleteDuplicates(h2);
    return 0;
}
