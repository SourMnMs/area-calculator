//
// Created by Theodore on 7/24/2025.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <vector>

// I was on some good shit when I wrote this.
// I tried to use this, and got some seggsy seg faults.

template<typename T>
struct ListNode
{
    ListNode* prev = this;
    ListNode* next = this;
    T* item = nullptr;

    explicit ListNode(T& i)
    {
        item = &i;
    }
    explicit ListNode(std::vector<T>& its)
    {
        item = &(its[0]);
        std::vector<T> nits = its;
        nits.erase(nits.begin());
        ListNode* curr = this;

        for (T& p : nits)
        {
            ListNode node{p};
            curr->addNode(node);
            curr = curr->next;
        }
    }
    void addNode(ListNode& n)
    {
        n.prev = this;
        n.next = next;
        next->prev = &n;
        next = &n;
    }
    void removeNextNode()
    {
        next->next->prev = this;
        next = next->next;
    }
    int length()
    {
        int count = 1;
        ListNode* curr = this;
        while (curr->next != this)
        {
            count++;
            curr = curr->next;
        }
        return count;
    }
};

#endif //LINKEDLIST_H
