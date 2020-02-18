#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* makeList(int* nums, int count);
void printList(struct ListNode* head);

struct ListNode* partition(struct ListNode* head, int x);

int main()
{
    int s1[] = {1,4,3,2,5,2};
    struct ListNode* l1 = makeList(s1, 6);
    printList(l1);
    struct ListNode* lp1 = partition(l1, 3);
    printList(lp1);

    int s2[] = {1,2};
    struct ListNode* l2 = makeList(s2, 2);
    printList(l2);
    struct ListNode* lp2 = partition(l2, 3);
    printList(lp2);

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
        printf((head->next != NULL) ? "%d->" : "%d\n", head->val);
}

/**
 * Maintain 2 lists, containing nodes < x and >= x respectively.
 * Join these 2 lists before return.
 */
struct ListNode* partition(struct ListNode* head, int x)
{
    struct ListNode *ah, *at, *bh, *bt;
    ah = at = bh = bt = NULL;

    for (; head; head = head->next) {
        if (head->val < x) {
            if (!ah) ah = at = head;
            else at = at->next = head;
        } else {
            if (!bh) bh = bt = head;
            else bt = bt->next = head;
        }
    }

    if (at) at->next = bh;
    if (bt) bt->next = NULL;

    return (ah) ? ah : bh;
}