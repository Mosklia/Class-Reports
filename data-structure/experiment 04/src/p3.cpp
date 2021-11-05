#include <iostream>

/**
 * Definition for singly-linked list.*/
struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int x = 0, ListNode *next = nullptr) : val(x), next(next) {}
};

ListNode *get_intersection(ListNode *headA, ListNode *headB)
{
    ListNode *tempA = headA;
    ListNode *tempB = headB;

    while (true)
    {
        if (tempA && tempA == tempB)
        {
            return tempA;
        }

        tempA = tempA->next;
        tempB = tempB->next;

        if (!tempA)
        {
            tempA = headB;
        }

        if (!tempB)
        {
            tempB = headA;
        }
    }
}

int main()
{
    ListNode *arr[5];
    arr[0] = new ListNode(1);
    arr[1] = new ListNode(2, arr[0]);
    arr[2] = new ListNode(3, arr[1]);
    arr[3] = new ListNode(4, arr[1]);
    arr[4] = new ListNode(5, arr[3]);

    std::cout << get_intersection(arr[4], arr[2])->val << std::endl;

    return 0;
}