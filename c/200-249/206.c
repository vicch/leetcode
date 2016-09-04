#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* makeList(int* nums, int count);
void printList(struct ListNode* head);
struct ListNode* reverseList(struct ListNode* head);

int main()
{
    int s1[] = {1,2,3,4};
    struct ListNode* l1 = makeList(s1, 4);
    printList(l1);
    l1 = reverseList(l1);
    printList(l1);

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
    for (; head != NULL; head = head->next) {
        printf("%d->", head->val);
    }
    printf("\n");
}

struct ListNode* reverseList(struct ListNode* head)
{
    if (head == NULL || head->next == NULL)
        return head;

    struct ListNode* p1 = head;
    struct ListNode* p2 = p1->next;
    struct ListNode* p3 = p2->next;

    p1->next = NULL;

    // 2 Nodes
    if (p3 == NULL) {
        p2->next = p1;
        return p2;
    }

    // >2 nodes
    do {
        p2->next = p1;
        p1 = p2;
        p2 = p3;
        p3 = p3->next;

    } while (p3 != NULL);

    p2->next = p1;

    return p2;
}