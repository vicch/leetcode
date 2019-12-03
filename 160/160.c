#include <stdio.h>

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB);

int main()
{
    return 0;
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
    struct ListNode* a = headA;
    struct ListNode* b = headB;

    if (a == NULL || b == NULL)
        return NULL;

    while (a != b) {
        a = a ? a->next : headB;
        b = b ? b->next : headA;
    }

    return a;
}