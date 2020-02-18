#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* makeList(int* nums, int count);
void printList(struct ListNode* head);
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);

int main()
{
    int seq1[10] = {1,1,0,4,7,2,7,3,0,1};
    int seq2[10] = {2,5,5,6,8,0,3,0,5,1};
    struct ListNode* l1 = makeList(seq1, 10);
    struct ListNode* l2 = makeList(seq2, 10);

    printList(l1);
    printList(l2);

    struct ListNode* sum = addTwoNumbers(l1, l2);
    printList(sum);

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

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;
    int sum = 0, carry = 0;

    while (l1 != NULL || l2 != NULL || carry == 1) {
        sum = carry + ((l1 == NULL) ? 0 : l1->val) + ((l2 == NULL) ? 0 : l2->val);
        carry = sum / 10;
        sum %= 10;

        struct ListNode* new = malloc(sizeof(struct ListNode));
        new->val = sum;
        new->next = NULL;

        if (tail != NULL) {
            tail->next = new;
            tail = new;
        } else
            head = tail = new;

        l1 = (l1 == NULL) ? NULL : l1->next;
        l2 = (l2 == NULL) ? NULL : l2->next;
    }

    return head;
}