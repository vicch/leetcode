"""
Basically get leaves of 2 trees and compare them. A leaf is a node without left or right child, so the recursion is:
- For a leave node, it has reached the bottom, return this node's value.
- Otherwise return its left node's leaves and right node's leaves recursively.
"""
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def leafSimilar(self, root1, root2):
        """
        :type root1: TreeNode
        :type root2: TreeNode
        :rtype: bool
        """
        def getLeaves(root):
            if not root:
                return []
            if not root.left and not root.right:
                return [root.val]
            return getLeaves(root.left) + getLeaves(root.right)

        return getLeaves(root1) == getLeaves(root2)
