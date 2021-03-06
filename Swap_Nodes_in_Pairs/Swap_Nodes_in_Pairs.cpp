// Swap_Nodes_in_Pairs.cpp : Defines the entry point for the console application.
// https://leetcode.com/problems/swap-nodes-in-pairs

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
    ListNode * swapPairs(ListNode* head)
    {
        ListNode* prev = nullptr;
        ListNode* newHead = head;
        for (auto node = head; node && node->next; node = node->next)
        {
            auto next = node->next;
            // 将上次循环的"尾部"和本次循环将要产生的新"头部"连接, 防止链表断裂
            if (prev)
            {
                prev->next = next;
            }

            if (next)
            {
                // 交换相邻的两个节点
                node->next = next->next;
                next->next = node;
                // 保存交换后的相邻节点的第二个节点, 用于下次循环
                prev = node;
                if (newHead == head)
                {
                    newHead = next;
                }
            }
        }

        return newHead;
    }
};

int main()
{
    Solution sln;
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    auto newHead = sln.swapPairs(head);

    auto head2 = new ListNode(1);
    auto newHead2 = sln.swapPairs(head2);
    return 0;
}
