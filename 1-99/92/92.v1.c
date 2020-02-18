#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* makeList(int* nums, int count);
void printList(struct ListNode* head);

struct ListNode* reverseBetween(struct ListNode* head, int m, int n);

int main()
{
    int s1[] = {3,5};
    struct ListNode* l1 = makeList(s1, 2);
    printList(l1);
    l1 =reverseBetween(l1, 1, 2);
    printList(l1);

    int s2[] = {1,2,3,4,5};
    struct ListNode* l2 = makeList(s2, 5);
    printList(l2);
    l2 =reverseBetween(l2, 1, 2);
    printList(l2);

    return 0;
}

struct ListNode* makeList(int* nums, int count)
{
    struct ListNode* head = malloc(sizeof(struct ListNode) * count);
    struct ListNode* node = head;

    for (; count > 0; count--, nums++, node++) {
        node->val = *nums;
        node->next = (count > 1) ? node + 1 : NULL;
    }

    return head;
}

void printList(struct ListNode* head)
{
    for (; head != NULL; head = head->next)
        printf((head->next) ? "%d->" : "%d\n", head->val);
}

struct ListNode* reverseBetween(struct ListNode* head, int m, int n)
{
    if (!head || !head->next || m == n) return head;

    // bp = breakpoint
    struct ListNode *bp, *p1, *p2, *p3;

    n -= m;
    if (m < 2) bp = NULL;
    else for (bp = head; m > 2; m--, bp = bp->next);

    p1 = (bp) ? bp->next : head;
    p2 = p1->next;
    p3 = NULL;

    for (; n > 0; n--) {
        p3 = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p3;
    }

    if (bp) {
        bp->next->next = p3;
        bp->next = p1;
        return head;
    } else {
        head->next = p3;
        return p1;
    }
}