// Problem:
// Given a binary tree, each node has a third pointer "next". Populate each
// "next" pointer to point to its next right node. If there is no next right
// node, the next pointer should be set to NULL.
// 
// Example:
// Input: 1
//       / \
//      2   3
//     / \   \
//    4   5   7
// Output: 1-> NULL
//        / \
//       2-> 3-> NULL
//      / \   \
//     4-> 5-> 7-> NULL
// 
// Solution:
// BFS the tree:
// - Add left and right child nodes to the queue if exists.
// - Use a counter to know when the end node of one row is reached.
// - Pop node from queue and set its "next" to the top node in queue.

#include <iostream>
#include <queue>

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode* root) {
        if (!root)
            return;

        int n, m;
        TreeLinkNode* node;
        queue<TreeLinkNode*> nodes;

        n = 1, m = 0;
        nodes.push(root);

        while (!nodes.empty()) {
            n--;
            node = nodes.front();
            nodes.pop();

            if (node->left)
                m++, nodes.push(node->left);
            if (node->right)
                m++, nodes.push(node->right);

            if (n == 0)
                n = m, m = 0;
            else
                node->next = nodes.front();
        }

        return;
    }
};