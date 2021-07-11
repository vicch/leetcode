# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
	def mergeTrees(self, root1, root2):
		"""
		:type root1: TreeNode
		:type root2: TreeNode
		:rtype: TreeNode
		"""
		if not root1:
			return root2
		if not root2:
			return root1
		return TreeNode(
			(root1.val if root1 else 0) + (root2.val if root2 else 0),
			# Merge leaf nodes recursively
			self.mergeTrees(root1.left if root1 else None, root2.left if root2 else None),
			self.mergeTrees(root1.right if root1 else None, root2.right if root2 else None)
		)