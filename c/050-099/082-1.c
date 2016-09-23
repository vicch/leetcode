#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* makeList(int* nums, int count);
void printList(struct ListNode* head);

struct ListNode* deleteDuplicates(struct ListNode* head);
struct ListNode* getNext(struct ListNode* l);

int main()
{

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

struct ListNode* deleteDuplicates(struct ListNode* head)
{
    head = getNext(head);
    if (head == NULL || head->next == NULL) return head;

    struct ListNode* tail = head;
    while (tail != NULL) {
        tail->next = getNext(tail->next);
        tail = tail->next;
    }

    return head;
}

/**
 * Get next non-duplicate node
 * e.g. 1->1->2->2->3->4->... returns 3->4->...
 */
struct ListNode* getNext(struct ListNode* list)
{
    if (list == NULL || list->next == NULL) return list;

    struct ListNode* p = NULL;
    int i = 0;

    do {
        p = (p == NULL) ? list : p->next;
        for (i = 0; p->next != NULL && p->val == p->next->val; p = p->next, i++);
    } while (i > 0 && p->next != NULL);
    
    return (i > 0) ? NULL : p;
}