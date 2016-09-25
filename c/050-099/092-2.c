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
    if (m == n) return head;
    n -= m ;

    // Dummy pointer before head, so when m == 1, the start pointer will still be valid
    struct ListNode* dummy = malloc(sizeof(struct ListNode));
    struct ListNode* pre = dummy;
    dummy->next = head;
    while (--m > 0) pre = pre->next;

    // Reverse list using only 2 moving pointers
    struct ListNode* p1 = pre->next;
    struct ListNode* p2;

    while (n-- > 0) {
        p2 = p1->next;
        p1->next = p2->next;
        p2->next = pre->next;
        pre->next = p2;
    }

    return dummy->next;
}