# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def invertTree(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        # Empty root is returned directly
        if root:
            # Don't need to check if left or right tree exists, empty trees are handled on next recursion automatically
            root.left, root.right = self.invertTree(root.right), self.invertTree(root.left)
        return root
