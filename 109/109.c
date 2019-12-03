#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct ListNode* makeList(int* nums, int count);

struct TreeNode* sortedListToBST(struct ListNode* head);
struct TreeNode* listToBST(struct ListNode* head, int len);

int main()
{
    int s1[] = {1,2,3,4,5,6};
    struct ListNode* l1 = makeList(s1, 6);
    struct TreeNode* t1 = sortedListToBST(l1);

    return 0;
}

struct ListNode* makeList(int* nums, int count)
{
    struct ListNode* head = malloc(sizeof(struct ListNode) * count);
    struct ListNode* node = head;

    for (; count > 0; count--, nums++, node++) {
        node->val = *nums;
        node->next = (count > 1) ? node + 1 : NULL;
    }

    return head;
}

struct TreeNode* sortedListToBST(struct ListNode* head)
{
    int len = 0;
    struct ListNode* p;

    // Get length
    for (len = 0, p = head; p != NULL; len++, p = p->next);

    return listToBST(head, len);
}

struct TreeNode* listToBST(struct ListNode* head, int len)
{
    if (len == 0) return NULL;

    int i, half;
    struct ListNode* mid;

    // Iterate to mid
    for (i = 0, half = len / 2, mid = head; i < half; i++, mid = mid->next);

    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    root->val = mid->val;
    root->left = listToBST(head, half);
    root->right = listToBST(mid->next, len-half-1);

    return root;
}