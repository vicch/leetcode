"""
Similar to #100 Same Tree, just recursively check if any sub-tree is the same tree as the target tree.
"""
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isSubtree(self, root, subRoot):
        """
        :type root: TreeNode
        :type subRoot: TreeNode
        :rtype: bool
        """
        def isSameTree(r1, r2):
            if not r1 and not r2:
                return True
            if not r1 or not r2 or r1.val != r2.val:
                return False
            return isSameTree(r1.left, r2.left) and isSameTree(r1.right, r2.right)

        return isSameTree(root, subRoot) or (root and self.isSubtree(root.left, subRoot)) or (root and self.isSubtree(root.right, subRoot))
