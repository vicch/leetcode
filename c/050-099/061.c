#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* makeList(int* nums, int count);
void printList(struct ListNode* head);

struct ListNode* rotateRight(struct ListNode* head, int k);
int getLength(struct ListNode* head);

int main()
{
    int seq1[] = {1,2,3,4,5};
    struct ListNode* lst1 = makeList(seq1, 5);
    printList(lst1);
    lst1 = rotateRight(lst1, 2);
    printList(lst1);

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
        printf("%d->", head->val);
    printf("\n");
}

struct ListNode* rotateRight(struct ListNode* head, int k)
{
    int l = getLength(head);
    if (l < 2) return head;

    k %= l;

    struct ListNode* fast = head;
    struct ListNode* slow = head;

    for (; k > 0; k--)
        fast = (fast->next) ? fast->next : head;
    for (; fast->next != NULL; fast = fast->next, slow = slow->next);

    fast->next = head;
    head = slow->next;
    slow->next = NULL;

    return head;
}

int getLength(struct ListNode* head)
{
    int i = 0;
    for (; head != NULL; head = head->next, i++);
    return i;
}