#include <iostream>

/**
 * Definition for singly-linked list.*/
struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int x = 0, ListNode *next = nullptr) : val(x), next(next)
    {
    }
};

ListNode *get_kth_back(ListNode *head, int k)
{
    auto temp = head;
    int len = 0;

    while (temp)
    {
        ++len;
        temp = temp->next;
    }

    while (len - k)
    {
        --len;
        head = head->next;
    }

    return head;
}

int main()
{
    ListNode *head = new ListNode(1), *temp = head;

    // Generate the test list.
    for (int i = 2; i <= 6; ++i)
    {
        temp->next = new ListNode(i);
        temp = temp->next;
    }

    for (int i = 1; i <= 6; ++i)
    {
        std::cout << get_kth_back(head, i)->val << ' ';
    }
}