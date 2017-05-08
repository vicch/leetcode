// Problem:
// A linked list is given such that each node contains an additional random
// pointer which could point to any node in the list or null. Return a deep
// copy of the list.
// 
// Solution:
// Use a hash map to store already created nodes, and DFS copy the next and
// random nodes for each node.

#include <iostream>
#include <map>

using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
    map<RandomListNode*, RandomListNode*> cache;

public:
    RandomListNode* copyRandomList(RandomListNode *head) {
        if (!head)
            return NULL;

        if (cache[head])
            return cache[head];

        RandomListNode* node = new RandomListNode(head->label);
        cache[head] = node;

        if (head->next) node->next = copyRandomList(head->next);
        if (head->random) node->random = copyRandomList(head->random);

        return node;
    }
};