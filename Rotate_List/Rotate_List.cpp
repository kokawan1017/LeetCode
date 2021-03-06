// Rotate_List.cpp : Defines the entry point for the console application.
// https://leetcode.com/problems/rotate-list/

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
    ListNode * rotateRight(ListNode* head, int k)
    {
        // 无需旋转的情况
        if (nullptr == head || nullptr == head->next || 0 == k)
        {
            return head;
        }

        // 计算链表长度
        auto tail = head;
        int length = 1;
        while (tail && tail->next)
        {
            ++length;
            tail = tail->next;
        }

        // 刚好还原链表, 故无需旋转
        if (0 == k % length)
        {
            return head;
        }

        // 将链表连接成环
        tail->next = head;

        // 计算步长, 将头尾指针向前移动
        int stepCount = length - k % length + 1;
        for (int i = 0; i < stepCount; i++)
        {
            head = head->next;
            tail = tail->next;
        }

        // 寻找新的尾节点
        while (head->next != tail)
        {
            head = head->next;
        }

        // 断开环
        head->next = nullptr;
        return tail;
    }
};

int main()
{
    Solution sln;
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    auto newHead = sln.rotateRight(head, 2);

    return 0;
}
