#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* makeList(int* seq, int count);
void printList(struct ListNode* head);

void reorderList(struct ListNode* head);
struct ListNode* halfenList(struct ListNode* head);
struct ListNode* reverseList(struct ListNode* head);
void weaveLists(struct ListNode* first, struct ListNode* second);

int main()
{
    int seq1[] = {1,2,3,4,5,6};
    struct ListNode* head1 = makeList(seq1, 6);
    printList(head1);
    reorderList(head1);
    printList(head1);

    int seq2[] = {1};
    struct ListNode* head2 = makeList(seq2, 1);
    printList(head2);
    reorderList(head2);
    printList(head2);

    return 0;
}

struct ListNode* makeList(int* seq, int count)
{
    if (!seq || count < 1) return NULL;

    struct ListNode *head, *tail, *new;
    int i;

    head = tail = NULL;
    for (i = 0; i < count; i++) {
        new = malloc(sizeof(struct ListNode));
        new->val = seq[i];
        new->next = NULL;

        if (!tail) head = tail = new;
        else tail = tail->next = new;
    }

    return head;
}

void printList(struct ListNode* head)
{
    for (; head; head = head->next)
        printf((head->next) ? "%d->" : "%d\n", head->val);
    return;
}

void reorderList(struct ListNode* head)
{
    if (!head || !head->next) return;

    struct ListNode* half;

    half = halfenList(head);
    half = reverseList(half);
    weaveLists(head, half);

    return;
}

/**
 * Cut a list of N nodes in half, return head pointer to the second half
 * If N is odd, the first half will be one node longer than the second
 */
struct ListNode* halfenList(struct ListNode* head)
{
    struct ListNode *slow, *fast;

    for (
        slow = fast = head;
        fast && fast->next && fast->next->next;
        slow = slow->next,
        fast = fast ? fast->next : fast,
        fast = fast ? fast->next : fast
    );

    // Reuse fast to point to the head node of the second half
    fast = slow->next;
    // Cut list
    slow->next = NULL;

    return fast;
}

struct ListNode* reverseList(struct ListNode* head)
{
    if (!head || !head->next) return head;

    struct ListNode *prev, *curr, *next;

    for (
        prev = NULL, curr = head, next = head->next;
        curr;
        prev = curr, curr = next,
        next = next ? next->next : next
    ) {
        curr->next = prev;
    }

    return prev;
}

/**
 * Join 2 lists A and B as A1->B1->A2->B2->...
 */
void weaveLists(struct ListNode* first, struct ListNode* second)
{
    if (!first || !second) return;

    struct ListNode *fcurr, *fnext, *scurr, *snext;

    for (
        fcurr = first, fnext = first->next,
        scurr = second, snext = second->next;
        scurr;
        fcurr = fnext, fnext = fnext ? fnext->next : fnext,
        scurr = snext, snext = snext ? snext->next : snext
    ) {
        fcurr->next = scurr;
        scurr->next = fnext;
    }

    return;
}