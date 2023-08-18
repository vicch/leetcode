"""
The LCA node is basically the node for which the p and q nodes are on different child trees (or one of them being the
ancestor node of the other), i.e. the node's value is between the values of p and q. So just traversing the tree from
root node, and move to proper child tree so that the next node's value moves towards the range between p and q.

As soon as there is no more movement to next level, the LCA node is found.

Time: O(logn) for balanced BST, otherwise O(n) for worst case
Space: O(1)
"""
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        # Let p be the smaller node for simplicity
        if p.val > q.val:
            p, q = q, p

        while root:
            # If both nodes are on right side, move to right tree
            if root.val > q.val:
                root = root.left
                continue
            # If both nodes are on left side, move to right tree
            if root.val < p.val:
                root = root.right
                continue
            # As soon as the nodes are on different sides, LCA node is found
            return root

        return None
