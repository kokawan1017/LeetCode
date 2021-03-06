// Design_Linked_List.cpp : Defines the entry point for the console application.
// https://leetcode.com/problems/design-linked-list/

#include "stdafx.h"
#include <assert.h>
#include <iostream>

class MyLinkedList
{
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(nullptr)
        {}
    };

public:
    /** Initialize your data structure here. */
    MyLinkedList()
    {

    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index)
    {
        auto node = findIndex(index);
        if (node)
        {
            return node->val;
        }

        return -1;
    }

    /** Add a node of value val before the first element of the linked list.
     * After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val)
    {
        if (!head_)
        {
            init(val);
            return;
        }

        ListNode* newNode = new ListNode(val);
        newNode->next = head_;
        head_ = newNode;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val)
    {
        if (!tail_)
        {
            init(val);
            return;
        }

        tail_->next = new ListNode(val);
        tail_ = tail_->next;
    }

    /** Add a node of value val before the index-th node in the linked list.
     * If index equals to the length of linked list, the node will be appended to the end of linked list.
     * If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val)
    {
        if (0 == index)
        {
            addAtHead(val);
            return;
        }

        auto node = findIndex(index - 1);
        if (node)
        {
            auto newNode = new ListNode(val);
            newNode->next = node->next;
            node->next = newNode;
            if (node == tail_)
            {
                tail_ = newNode;
            }
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index)
    {
        auto node = findIndex(index - 1);
        if (node && node->next)
        {
            auto target = node->next;
            auto afterTarget = target->next;
            delete target;
            node->next = afterTarget;
            if (target == tail_)
            {
                tail_ = node;
            }
        }
    }

private:
    /*
     * 这里对于index < 0的返回结果并不符合逻辑, 即可能返回有效的head节点
     * 但这种情况的判断交给了调用者(即 addAtIndex 和 deleteAtIndex 方法)
     * 目的是为了让这两个方法可以通过 findIndex 的返回值来判断index是否有效
     */
    ListNode* findIndex(int index)
    {
        auto node = head_;
        for (int i = 0; i < index && node; i++)
        {
            node = node->next;
        }

        return node;
    }

    void init(int val)
    {
        assert(nullptr == head_ && nullptr == tail_);

        head_ = new ListNode(val);
        tail_ = head_;
    }

private:
    ListNode* head_ = nullptr;
    ListNode* tail_ = nullptr;
};


/**
* Your MyLinkedList object will be instantiated and called as such:
* MyLinkedList* obj = new MyLinkedList();
* int param_1 = obj->get(index);
* obj->addAtHead(val);
* obj->addAtTail(val);
* obj->addAtIndex(index,val);
* obj->deleteAtIndex(index);
*
* 下标index从0开始计数
*/

int main()
{
    MyLinkedList* list = new MyLinkedList();
    list->addAtTail(2);
    list->addAtTail(3);
    list->addAtTail(4);

    list->addAtIndex(0, 1);
    list->addAtIndex(4, 5);
    return 0;
}
