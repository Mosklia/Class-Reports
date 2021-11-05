#include <iostream>

/**
 * Definition for singly-linked list.*/
struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int x = 0, ListNode *next = nullptr) : val(x), next(next) {}
};

bool check_cycle(ListNode *head)
{
    ListNode *slow = head, *fast = head;

    while (true)
    {
        slow = slow->next;
        fast = fast->next;

        if (!fast)
        {
            return false;
        }

        fast = fast->next;

        if (!fast)
        {
            return false;
        }
        else if(fast == slow)
        {
            return true;
        }
    }
}

int main()
{
    ListNode *cycle[5], *no_cycle[5];

    no_cycle[0] = new ListNode(0);
    no_cycle[1] = new ListNode(1, no_cycle[0]);
    no_cycle[2] = new ListNode(2, no_cycle[1]);

    cycle[0] = new ListNode(0);
    cycle[1] = new ListNode(1, cycle[0]);
    cycle[2] = new ListNode(2, cycle[1]);
    cycle[0]->next = cycle[2];

    std::cout << check_cycle(no_cycle[2]) << std::endl;
    std::cout << check_cycle(cycle[2]) << std::endl;
}