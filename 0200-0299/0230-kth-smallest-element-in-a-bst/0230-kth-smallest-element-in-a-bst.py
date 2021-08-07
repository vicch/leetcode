"""
Get the k-th smallest element in a BST, is basically getting the k-th element in the inorder representation of the BST.
So by traversing the BST as inorder, then when the k-th element is found, just return it.

The trick part is to pop up the correct value from the recursions when doing DFS traversal. If the value is not found
on a tree, it needs to return a special value, e.g. None, and if the return value from any child tree is not None, pop
it all the way up.
"""
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def kthSmallest(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: int
        """
        self.counter = k

        def visit(node):
            if not node:
                return

            left = visit(node.left)
            # If value found on left tree, pop it up
            if left is not None:
                return left

            self.counter -= 1
            # Current root the value being looked for
            if self.counter == 0:
                return node.val

            right = visit(node.right)
            # If value found on right tree, pop it up
            if right is not None:
                return right

            # If value not found on current tree, return empty
            return None

        return visit(root)
