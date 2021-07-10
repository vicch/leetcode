// Problem:
// A linked list is given such that each node contains an additional random
// pointer which could point to any node in the list or null. Return a deep
// copy of the list.
// 
// Solution:
// 1. Build a new list by creating a new node l2 for each node l1 in old list.
// 2. Insert each node l2 as its corresponding node l1's "next" node.
// 3. Fix "random" pointers as now l2->random should be l1->random->next.
// 4. Separate the 2 lists by resetting l1 and l2's "next" node.

#include <iostream>

using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL)
            return NULL;

        RandomListNode *head2, *l1, *l2;

        for (l1 = head; l1 != NULL; l1 = l1->next->next) {
            l2 = new RandomListNode(l1->label);
            l2->next = l1->next;
            l1->next = l2;
        }
            
        head2 = head->next;
        for (l1 = head; l1 != NULL; l1 = l1->next->next) {
            if (l1->random != NULL)
                l1->next->random = l1->random->next;
        }
            
        for (l1 = head; l1 != NULL; l1 = l1->next) {
            l2 = l1->next;
            l1->next = l2->next;
            if (l2->next != NULL)
                l2->next = l2->next->next;
        }

        return head2;
    }
};