// Problem:
// 

#include <iostream>
#include <cstdlib>
#include <cstring>

#define coord(x, y) ((1 << (x)) - 1 + (y))

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    TreeNode** matrix;

public:
    int countNodes(TreeNode* root) {
        if (root == NULL)
            return 0;
        
        int ldepth = leftDepth(root);
        int rdepth = rightDepth(root);
        int count = (1 << (rdepth + 1)) - 1;

        if (ldepth == rdepth)
            return count;

        matrix = (TreeNode**)malloc(sizeof(TreeNode*) * count);
        memset(matrix, 0, sizeof(TreeNode*) * count);
        matrix[0] = root;

        int l, m, r;

        for (l = 0, r = (1 << rdepth) - 1, m = (l + r) / 2; l < m; m = (l + r) / 2) {
            populateMatrix(rdepth, m);

            if (matrix[coord(rdepth, m)]->left && matrix[coord(rdepth, m)]->right)
                l = m;
            else if (!matrix[coord(rdepth, m)]->left && !matrix[coord(rdepth, m)]->right)
                r = m;
            else
                break;
        }

        count += m * 2;

        populateMatrix(rdepth, m);
        count += matrix[coord(rdepth, m)]->right ? 2 : 1;
        
        populateMatrix(rdepth, r);
        count += (r > m && matrix[coord(rdepth, r)]->left) ? 1 : 0;

        return count;
    }

    void populateMatrix(int x, int y) {
        cout << "x = " << x << ", y = " << y << endl;

        // Already populated
        if (matrix[coord(x, y)] != NULL)
            return;

        // Populate parent node
        int px = x - 1, py = y / 2;
        populateMatrix(px, py);

        // Populate this node
        matrix[coord(x, y)] = (y % 2) ? matrix[coord(px, py)]->right : matrix[coord(px, py)]->left;

        return;
    }
    
    int leftDepth(TreeNode* root) {
        int depth;
        for (depth = 0; root->left != NULL; root = root->left, depth++);
        return depth;
    }
    
    int rightDepth(TreeNode* root) {
        int depth;
        for (depth = 0; root->right != NULL; root = root->right, depth++);
        return depth;
    }
};