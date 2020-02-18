#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* arrayToTree(int* seq, int total, int index);
int treeToArray(int* seq, int index, struct TreeNode* root);
void printArray(int* seq, int count);

int isSymmetric(struct TreeNode* root);

// int treeTraverse(int* seq, struct TreeNode* root, int dir);

int getChildren(struct TreeNode** cnodes, struct TreeNode** pnodes, int pcount);
int checkSymmetric(struct TreeNode** nodes, int count);
void printValues(struct TreeNode** nodes, int count);

int main()
{
    // int seq[] = {2,3,3,4,5,5,4,-1,-1,8,9,9,8,-1,-1};
    // int seq[] = {1,2,3,3,-1,2,-1};
    int seq[] = {5,4,1,-1,1,-1,4,-1,-1,2,-1,-1,-1,2,-1};
    struct TreeNode* root = arrayToTree(seq, 15, 1);

    int res = isSymmetric(root);

    printArray(seq, 15);
    printf((res == 1) ? "Symmetric\n" : "Not Symmetric\n");

    return 0;
}

struct TreeNode* arrayToTree(int* seq, int total, int index)
{
    if (seq[index - 1] == -1)
        return NULL;

    struct TreeNode* root = malloc(sizeof(struct TreeNode));

    root->val   = seq[index - 1];
    root->left  = NULL;
    root->right = NULL;

    if (index * 2 <= total)
        root->left = arrayToTree(seq, total, index * 2);

    if (index * 2 + 1 <= total)
        root->right = arrayToTree(seq, total, index * 2 + 1);

    return root;
}

int treeToArray(int* seq, int index, struct TreeNode* root)
{
    if (root == NULL)
        return 0;

    int lc, rc;

    seq[index - 1] = root->val;
    lc = treeToArray(seq, index * 2, root->left);
    rc = treeToArray(seq, index * 2 + 1, root->right);

    return lc + rc + 1;
}

void printArray(int* seq, int count)
{
    while (count-- > 0) {
        printf((count > 0) ? "%d," : "%d", *seq++);
    }
    printf("\n");
}

int isSymmetric(struct TreeNode* root)
{
    struct TreeNode** pnodes = malloc(sizeof(struct TreeNode*) * 1);
    struct TreeNode** cnodes = malloc(sizeof(struct TreeNode*) * 2);
    int pcount, ccount;

    *pnodes = root;
    pcount = 1;

    // Get children nodes
    while ((ccount = getChildren(cnodes, pnodes, pcount)) != 0) {

        // Get if children nodes values are symmetric
        if (checkSymmetric(cnodes, ccount) == 0)
            return 0;

        // Prepare for next level children nodes
        pnodes = cnodes;
        pcount = ccount;
        cnodes = malloc(sizeof(struct TreeNode*) * ccount * 2);
    }

    return 1;
}

int getChildren(struct TreeNode** cnodes, struct TreeNode** pnodes, int pcount)
{
    int ccount = 0;

    while (pcount-- > 0) {
        if (*pnodes != NULL) {
            cnodes[ccount++] = (*pnodes)->left;
            cnodes[ccount++] = (*pnodes)->right;
        }
        pnodes++;
    }

    // printValues(cnodes, ccount);

    return ccount;
}

int checkSymmetric(struct TreeNode** nodes, int count)
{
    int i, lv, rv;

    for (i = 0; i < count/2; i++) {
        lv = (*(nodes + i) == NULL) ? -1 : (*(nodes + i))->val;
        rv = (*(nodes + count - 1 - i) == NULL) ? -1 : (*(nodes + count - 1 - i))->val;
        if (lv != rv)
            return 0;
    }

    return 1;
}

void printValues(struct TreeNode** nodes, int count)
{
    while (count-- > 0) {
        (*nodes == NULL) ? printf("-1 ") : printf("%d ", (*nodes)->val);
        nodes++;
    }
    printf("\n");
}

// int treeTraverse(int* seq, struct TreeNode* root, int dir)
// {
//     int lc, rc;

//     if (root == NULL) {
//         *seq = -1;
//         return 1;
//     }

//     if (root->left == NULL && root->right == NULL) {
//         *seq = root->val;
//         return 1;
//     }

//     // LDR
//     if (dir == 0) {
//         lc = treeTraverse(seq, root->left, dir);
//         *(seq + lc) = root->val;
//         rc = treeTraverse(seq + lc + 1, root->right, dir);

//     // RDL
//     } else {
//         rc = treeTraverse(seq, root->right, dir);
//         *(seq + rc) = root->val;
//         lc = treeTraverse(seq + rc + 1, root->left, dir);
//     }
    
//     return lc + rc + 1;
// }
