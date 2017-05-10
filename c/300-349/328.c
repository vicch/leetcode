// Problem:
// Given a singly linked list, group all odd nodes together followed by the
// even nodes. Please note here we are talking about the node number and not
// the value in the nodes. The program should run in O(1) space complexity and
// O(N) time complexity.
// 
// Example:
// Input: 1->2->3->4->5->NULL
// Output: 1->3->5->2->4->NULL
// 
// Solution:
// Use 2 pointers to the tail of the odd nodes and even nodes, manipulate the
// next node to the tail of even nodes and move it to the tail of odd nodes,
// and move the 2 tails forward till the even nodes tail reaches the end.

#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

int main()
{
    return 0;
}

/********** Solution **********/

struct ListNode* oddEvenList(struct ListNode* head)
{
    if (!head || !head->next)
        return head;

    struct ListNode *otail, *etail, *move;

    for (otail = head, etail = head->next; etail && etail->next;) {
        move = etail->next;
        etail->next = move->next, etail = move->next;
        move->next = otail->next;
        otail->next = move, otail = move;
    }

    return head;
}