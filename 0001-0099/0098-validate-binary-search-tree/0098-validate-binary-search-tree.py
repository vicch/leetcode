"""
By defintion, for each node in a BST:

- All nodes on its left tree must be smaller than this node's value.
- All nodes on its right tree must be larger than this node's value.

The boundaries and transitive and only become more strict for all sub-trees at lower level. So just pass the current
left and right border for each tree node, and update the borders to recursively check sub-trees.
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
            if (left is not None and root.val <= left) or (right is not None and root.val >= right):
                return False
            # Recursively check child trees
            return isValid(root.left, left, root.val) and isValid(root.right, root.val, right)

        # Use none to indicate no limit
        return isValid(root, None, None)
