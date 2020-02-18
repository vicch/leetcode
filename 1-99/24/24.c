#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct List {
    struct ListNode* head;
    struct ListNode* tail;
};

struct ListNode* makeList(int* nums, int len);
void printList(struct ListNode* head);
struct ListNode* swapPairs(struct ListNode* head);

int main()
{
    int seq[] = {1,0,0,1};
    struct ListNode* lh = makeList(seq, 4);
    printList(lh);

    lh = swapPairs(lh);
    printList(lh);

    return 0;
}

struct ListNode* makeList(int* nums, int len)
{
    int i;
    struct ListNode* new;
    struct List* list = malloc(sizeof(struct List));

    if (len == 0)
        return NULL;

    for (i = 0; i < len; i++) {
        new = malloc(sizeof(struct ListNode));
        new->val = nums[i];
        new->next = NULL;

        if (i == 0) {
            list->head = new;
        } else {
            list->tail->next = new;
        }
        list->tail = new;
    }

    return list->head;
}

void printList(struct ListNode* head)
{
    struct ListNode *iter;

    if (head == NULL) {
        printf("\n");
        return;
    }

    iter = head;
    while (iter->next != NULL) {
        printf("%d->", iter->val);
        iter = iter->next;
    }
    printf("%d\n", iter->val);
}

struct ListNode* swapPairs(struct ListNode* head)
{
    struct ListNode* node;
    int i;

    // Less than 2 nodes eft, no swap
    if (head == NULL || head->next == NULL)
        return head;

    // Swap
    node = head->next;
    head->next = node->next;
    node->next = head;

    if (head->next != NULL)
        head->next = swapPairs(head->next);

    return node;
}