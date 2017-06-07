// Problem:
// Given a binary tree, find the lowest common ancestor (LCA) of two given
// nodes in the tree. The lowest common ancestor is defined between two nodes v
// and w as the lowest node in T that has both v and w as descendants (where we
// allow a node to be a descendant of itself).
// 
// Solution:
// Recursively search the 2 nodes in the tree. Store paths from root to the
// nodes in vectors (or queues). When both nodes are found, return. Iterate
// the 2 paths until one reaches the end or corresponding nodes don't match,
// return the last matching node in the vector.
// 
// Example:
// Path to p is {-1, 0, 3}, Path to p is {-1, 0, 2}, return 0

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    TreeNode* np;
    TreeNode* nq;
    vector<TreeNode*> path;
    vector<TreeNode*> pathp;
    vector<TreeNode*> pathq;

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || !p || !q)
            return NULL;

        np = p;
        nq = q;

        markPath(root);

        // Either node is not found
        if (!pathp.size() || !pathq.size())
            return NULL;

        int i;
        for (i = 0; i < pathp.size() && i < pathq.size() && pathp[i] == pathq[i]; i++);

        return pathp[i - 1];
    }

    bool markPath(TreeNode* root) {
        path.push_back(root);

        if (!pathp.size() && root == np) pathp = path;
        if (!pathq.size() && root == nq) pathq = path;

        if (pathp.size() && pathq.size()) return true;

        if (root->left && markPath(root->left)) return true;
        if (root->right && markPath(root->right)) return true;

        path.pop_back();

        return false;
    }
};

int main() {
    TreeNode* n1 = new TreeNode(-1);
    TreeNode* n2 = new TreeNode(0);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n4 = new TreeNode(-2);
    TreeNode* n5 = new TreeNode(4);
    TreeNode* n6 = new TreeNode(8);

    n1->left  = n2;
    n1->right = n3;
    n2->left  = n4;
    n2->right = n5;
    n4->left  = n6;

    Solution s;
    TreeNode* nx = s.lowestCommonAncestor(n1, n2, n6);
    cout << nx->val << endl;

    return 0;
}