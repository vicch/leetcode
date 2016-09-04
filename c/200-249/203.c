#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* makeList(int* nums, int count);
void printList(struct ListNode* head);
struct ListNode* removeElements(struct ListNode* head, int val);

int main()
{
    int s1[] = {1,2,2,1};
    struct ListNode* l1 = makeList(s1, 4);
    printList(l1);
    l1 = removeElements(l1, 2);
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

struct ListNode* removeElements(struct ListNode* head, int val)
{
    if (head == NULL)
        return NULL;

    struct ListNode* cur = head;
    struct ListNode* last = NULL;

    while (cur != NULL && cur->val == val) {
        cur = cur->next;
        head = cur;
    }

    if (cur == NULL)
        return NULL;

    for (; cur != NULL; last = cur, cur = cur->next) {
        if (cur->val == val) {
            last->next = cur->next;
            cur = last;
        }
    }

    return head;
}