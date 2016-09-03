// https://leetcode.com/problems/add-two-numbers/
#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode* next;
};

struct ListNode* createList(int seq[], int len);
struct ListNode* addLists(struct ListNode* l1, struct ListNode* l2);

int main()
{
    int seq1[10] = {1,1,0,4,7,2,7,3,0,1};
    int seq2[10] = {2,5,5,6,8,0,3,0,5,1};
    struct ListNode *l1, *l2, *sum, *iter;

    l1 = createList(seq1, 10);
    l2 = createList(seq2, 10);
    sum = addLists(l1, l2);

    iter = sum;
    while (iter != NULL) {
        printf("%d\n", iter->val);
        iter = iter->next;
    }

    return 0;
}

struct ListNode* createList(int seq[], int len)
{
    struct ListNode *head, *cur, *next;
    int i;

    head = cur = malloc(sizeof(struct ListNode));
    cur->val = seq[0];

    for (i = 1; i < len; i++) {
        next = malloc(sizeof(struct ListNode));
        next->val = seq[i];
        cur->next = next;
        cur = next;
    }

    return head;
}

struct ListNode* addLists(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode *head, *cur, *next;
    int val1, val2, sum, carry;

    sum = l1->val + l2->val;
    if (sum > 9) {
        sum -= 10;
        carry = 1;
    } else {
        carry = 0;
    }
    head = cur = malloc(sizeof(struct ListNode));
    head->val = sum;
    
    while (l1->next != NULL || l2->next != NULL || carry > 0) {
        if (l1->next != NULL) {
            l1 = l1->next;
            val1 = l1->val;
        } else {
            val1 = 0;
        }
            
        if (l2->next != NULL) {
            l2 = l2->next;
            val2 = l2->val;
        } else {
            val2 = 0;
        }

        sum = val1 + val2 + carry;
        if (sum > 9) {
            sum -= 10;
            carry = 1;
        } else {
            carry = 0;
        }

        next = malloc(sizeof(struct ListNode));
        next->val = sum;
        cur->next = next;
        cur = next;
    }

    return head;
}