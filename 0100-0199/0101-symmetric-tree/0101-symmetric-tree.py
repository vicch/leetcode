"""
By definition, 2 trees are symmetric if their values are equal, and their child trees are symmetric: tree 1's left tree
is symmetric with tree 2's right, and vice versa.
"""

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        def dfs(root1, root2):
            if not root1 and not root2:
                return True
            if not root1 or not root2 or root1.val != root2.val:
                return False
            # Recursive check child trees being symmetric
            return dfs(root1.left, root2.right) and dfs(root1.right, root2.left)

        # Check if first level left and right trees are symmetric
        return root and dfs(root.left, root.right)
