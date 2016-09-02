#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* makeList(int* nums, int count, int loopBack);
void printList(struct ListNode *head, int count);
int hasCycle(struct ListNode *head);

int main()
{
    clock_t begin = clock();

    int seq1[] = {1,2,3,4};
    struct ListNode* list1 = makeList(seq1, 4, 1);
    printList(list1, 10);
    printf("%d\n", hasCycle(list1));

    int seq2[] = {-1,-7,7,-4,19,6,-9,-5,-2,-5};
    struct ListNode* list2 = makeList(seq2, 10, 6);
    printList(list2, 20);
    printf("%d\n", hasCycle(list2));

    clock_t end = clock();
    double msecond = (double)(end - begin) / CLOCKS_PER_SEC * 1000;
    printf("%f ms.\n", msecond);

    return 0;
}

struct ListNode* makeList(int* nums, int count, int loopIndex)
{
    int i;
    struct ListNode *head, *tail, *new, *loopNode;

    head = malloc(sizeof(struct ListNode));
    head->val = nums[0];
    tail = head;

    for (i = 1; i < count; i++) {
        new = malloc(sizeof(struct ListNode));
        new->val = nums[i];
        new->next = NULL;
        
        tail->next = new;
        tail = new;

        if (i == loopIndex)
            loopNode = new;
    }

    tail->next = loopNode;

    return head;
}

void printList(struct ListNode *head, int count)
{
    while (count-- > 0 && head != NULL) {
        printf("%d->", head->val);
        head = head->next;
    }
    printf("\n");
}

/**
 * Make every node points back to its predecessor while iterating forward,
 * so if there is a cycle, it will iterate back to head
 */
int hasCycle(struct ListNode *head)
{
    if (head == NULL || head->next == NULL || head->next->next == NULL)
        return 0;

    if (head->next == head || head->next->next == head)
        return 1;

    struct ListNode* p1 = head;
    struct ListNode* p2 = p1->next;
    struct ListNode* p3 = p2->next;

    while (p3 != NULL && p3 != head) {
        p2->next = p1;
        p1 = p2;
        p2 = p3;
        p3 = p3->next;
    }

    return (p3 == head);
}