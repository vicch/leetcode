// Problem:
// Given a binary tree, compute the length of the diameter of the tree. The
// diameter of a binary tree is the length of the longest path between any two
// nodes in a tree. This path may or may not pass through the root.
// 
// Example:
// Input: 1
//       / \
//      2   3
//     / \
//    4   5
// Output: 3
// 
// Solution:
// Recursively compute the diameter for each node, and return 2 values:
// - The depth of all child trees of this node, which equals to 1 + the larger
//   one between "left child tree's depth" and "right child tree's depth".
// - The diameter of this node, which equals the largest one between "left
//   child tree's depth + right child tree's depth + 2" and "left child tree's
//   diameter" and "right child tree's diameter".

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        vector<int> len = diameterSub(root);
        return len[1];
    }

    vector<int> diameterSub(TreeNode* root) {
        if (!root) return vector<int>(2, -1);

        vector<int> llen = diameterSub(root->left);
        vector<int> rlen = diameterSub(root->right);

        return vector<int> {
            max(llen[0], rlen[0]) + 1,
            max(llen[0] + rlen[0] + 2, max(llen[1], rlen[1]))
        };
    }
};