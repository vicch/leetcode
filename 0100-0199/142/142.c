#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* makeList(int* nums, int count, int loopBack);
void printList(struct ListNode *head, int count);

struct ListNode *detectCycle(struct ListNode *head);

int main()
{
    int seq1[] = {1,2,3,4};
    struct ListNode* list1 = makeList(seq1, 4, 1);
    printList(list1, 10);
    struct ListNode* node1 = detectCycle(list1);
    printf("%d\n", node1->val);

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

struct ListNode *detectCycle(struct ListNode *head)
{
    if (!head) return NULL;

    int i, diff, max = 10000;
    struct ListNode *fast, *slow;

    // Find diff, which is size of the cycle times N
    for (diff = 1, fast = head->next, slow = head;
         fast && slow && (fast != slow) && (diff <= max);
         diff++, fast = fast->next, fast = (fast) ? fast->next : fast, slow = slow->next
    );

    // Cycle not found
    if (!fast || diff == max)
        return NULL;

    // Fast pointer goes diff nodes ahead
    for (i = 0, fast = head; i < diff; i++, fast = fast->next);

    // When fast and slow pointers meet, it's the cycle start
    for (slow = head; fast != slow; fast = fast->next, slow = slow->next);

    return fast;
}