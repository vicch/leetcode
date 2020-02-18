#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n);
void printListNodes(struct ListNode* head);

int main()
{
    struct ListNode *a = malloc(sizeof(struct ListNode));
    struct ListNode *b = malloc(sizeof(struct ListNode));
    struct ListNode *c = malloc(sizeof(struct ListNode));
    struct ListNode *d = malloc(sizeof(struct ListNode));
    struct ListNode *e = malloc(sizeof(struct ListNode));

    a->val = 1;
    // b->val = 2;
    // c->val = 3;
    // d->val = 4;
    // e->val = 5;

    a->next = NULL;
    // a->next = b;
    // b->next = c;
    // c->next = d;
    // d->next = e;
    // e->next = NULL;

    printListNodes(a);
    a = removeNthFromEnd(a, 1);
    printListNodes(a);

    return 0;
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    struct ListNode* nodes[1000];
    struct ListNode* iter;
    int l;

    iter = head;
    for (l = 0; iter->next != NULL && l < 1000; l++) {
        nodes[l] = iter;
        iter = iter->next;
    }
    // Last node
    nodes[l] = iter;

    if (n == 1) {
        if (l == 0) {
            // Remove only node
            head = NULL;
        } else {
            // Remove last node
            nodes[l-1]->next = NULL;
        }

    } else if (n == l + 1) {
        // Remove first node
        head = nodes[1];

    } else {
        nodes[l-n]->next = nodes[l-n+2];
    }

    return head;
}

void printListNodes(struct ListNode* head)
{
    struct ListNode *iter;

    iter = head;
    while (iter->next != NULL) {
        printf("%d->", iter->val);
        iter = iter->next;
    }
    printf("%d\n", iter->val);
}