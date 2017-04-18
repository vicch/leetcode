// Problem:
// Given a binary tree, find the leftmost value in the last row of the tree.
// Assume the tree (i.e., the given root node) is not NULL.
// 
// Example:
// Input:
//     1
//    / \
//   2   3
//  /   / \
// 4   5   6
//    /
//   7
// Output: 7
// 
// Solution:
// Use a queue to store tree nodes. Push current root's right and left nodes in
// queue. Take next node from queue as root. Continue until queue is empty.
// Current root node is the asked node.

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int findBottomLeftValue(struct TreeNode* root);

int main()
{
    return 0;
}

/********** Solution **********/

struct Queue {
    struct TreeNode** nodes;
    int size;
    int head;
    int tail;
};

struct Queue* create(int size);
void push(struct Queue* queue, struct TreeNode* node);
struct TreeNode* pop(struct Queue* queue);
int empty(struct Queue* queue);
void destroy(struct Queue* queue);

int findBottomLeftValue(struct TreeNode* root)
{
    struct Queue* queue = create(10000);

    push(queue, root);
    while (!empty(queue)) {
        root = pop(queue);
        if (root->right)
            push(queue, root->right);
        if (root->left)
            push(queue, root->left);
    }

    return root->val;
}

struct Queue* create(int size)
{
    struct Queue* queue = malloc(sizeof(struct Queue));
    queue->nodes = malloc(sizeof(struct TreeNode*) * size);
    queue->size = size;
    queue->head = queue->tail = 0;
    return queue;
}

void push(struct Queue* queue, struct TreeNode* node)
{
    queue->nodes[(queue->tail)++] = node;
    if (queue->tail == queue->size)
        queue->tail = 0;
    return;
}

struct TreeNode* pop(struct Queue* queue)
{
    struct TreeNode* node = queue->nodes[(queue->head)++];
    if (queue->head == queue->size)
        queue->head = 0;
    return node;
}

int empty(struct Queue* queue)
{
    return queue->head == queue->tail;
}

void destroy(struct Queue* queue)
{
    free(queue->nodes);
    free(queue);
    return;
}