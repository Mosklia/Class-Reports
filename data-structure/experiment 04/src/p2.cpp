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

ListNode *reverse(ListNode *head)
{
    if (head && head->next)
    {
        auto temp = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return temp;
    }
    else
    {
        return head;
    }
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

    head = reverse(head);

    temp = head;
    while (temp)
    {
        std::cout << temp->val << ' ';
        temp = temp->next;
    }
}