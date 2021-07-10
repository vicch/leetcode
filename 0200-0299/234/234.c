#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef int bool;

struct ListNode* makeList(int* nums, int count);
void printList(struct ListNode* head);

int listLen(struct ListNode* head);
struct ListNode* getNode(struct ListNode* head, int idx);
struct ListNode* reverseList(struct ListNode* head, int count);
bool isPalindrome(struct ListNode* head);

int main()
{
    int s1[] = {1,1};
    struct ListNode* l1 = makeList(s1, 2);
    printf("%d\n", isPalindrome(l1));

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

int listLen(struct ListNode* head)
{
    int i = 0;

    while (head != NULL) {
        i += 1;
        head = head->next;
    }

    return i;
}

struct ListNode* getNode(struct ListNode* head, int idx)
{
    while (head != NULL && idx-- > 0) {
        head = head->next;
    }

    return head;
}

struct ListNode* reverseList(struct ListNode* head, int count)
{
    if (head == NULL || head->next == NULL)
        return head;

    struct ListNode* p1 = head;
    struct ListNode* p2 = head->next;
    struct ListNode* p3;

    head->next = NULL;

    while (p2 != NULL && count-- > 1) {
        p3 = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p3;
    }

    return p1;
}

bool isPalindrome(struct ListNode* head)
{
    int l = listLen(head);
    struct ListNode* l2 = getNode(head, (l + 1) / 2);
    struct ListNode* l1 = reverseList(head, l / 2);

    for (; l1 != NULL && l2 != NULL; l1 = l1->next, l2 = l2->next) {
        if (l1->val != l2->val)
            return 0;
    }

    return 1;
}