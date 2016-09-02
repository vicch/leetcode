#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2);
int getNextVal(struct ListNode** l1, struct ListNode** l2);

int main()
{
    int seq1[] = {};
    struct ListNode* lh1 = makeList(seq1, 0);
    printList(lh1);

    int seq2[] = {-5, 1};
    struct ListNode* lh2 = makeList(seq2, 2);
    printList(lh2);

    struct ListNode* lh3 = mergeTwoLists(lh1, lh2);
    printList(lh3);

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

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode* head;
    struct ListNode* tail;
    struct ListNode* new;
    int val;

    head = tail = NULL;
    while ((val = getNextVal(&l1, &l2)) != INT_MAX) {
        new = malloc(sizeof(struct ListNode));
        new->val = val;
        new->next = NULL;

        if (head == NULL) {
            head = new;
        } else {
            tail->next = new;
        }
        tail = new;
    }

    return head;
}

int getNextVal(struct ListNode** l1, struct ListNode** l2)
{
    int val;

    if (*l1 != NULL || *l2 != NULL) {
        if (*l1 == NULL) {
            val = (*l2)->val;
            *l2 = (*l2)->next;
        } else if (*l2 == NULL) {
            val = (*l1)->val;
            *l1 = (*l1)->next;
        } else {
            if ((*l1)->val < (*l2)->val) {
                val = (*l1)->val;
                *l1 = (*l1)->next;
            } else {
                val = (*l2)->val;
                *l2 = (*l2)->next;
            }
        }
    } else {
        val = INT_MAX;
    }

    return val;
}