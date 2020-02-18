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
struct ListNode* deleteDuplicates(struct ListNode* head);

int main()
{
    int seq[] = {1,1,1,1,1};
    struct ListNode* lh = makeList(seq, 5);
    printList(lh);

    lh = deleteDuplicates(lh);
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

struct ListNode* deleteDuplicates(struct ListNode* head)
{
    struct ListNode *l, *c;

    if (head == NULL || head->next == NULL)
        return head;

    l = head;
    c = head->next;
    while (c != NULL) {
        if (c->val == l->val) {
            l->next = c->next;
        } else {
            l = c;
        }
        c = c->next;
    }

    return head;
}