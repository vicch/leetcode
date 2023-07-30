"""
By defintion, for each node in a BST:

- All nodes on its left tree must be smaller than this node's value.
- All nodes on its right tree must be larger than this node's value.

The boundaries are transitive, and become more strict for sub-trees at lower level. So just pass the current
left and right boundary for each tree node recursively, and update accordingly.
"""
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        def isValid(root, left, right):
            if not root:
                return True
            # If current node is out of range, it's not valid
            if root.val <= left or root.val >= right:
                return False
            # Recursively check child trees
            return isValid(root.left, left, root.val) and isValid(root.right, root.val, right)

        # Use none to indicate no limit
        return isValid(root, float('-inf'), float('inf'))
