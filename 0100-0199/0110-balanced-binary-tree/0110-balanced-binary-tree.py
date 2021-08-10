"""
Similar to #104 Maximum Depth of Binary Tree, where the max depths of child trees determine if a binary tree is
balanced. The difference is, as soon as a sub-tree is unbalanced, the DFS traversal can return right away. And to do
this, a special return value -1 can be used to indicate a sub-tree is unbalanced, because normal DFS to get tree depth
won't return -1.
"""
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """

        def getDepth(root):
            if not root:
                return 0

            left = getDepth(root.left)
            right = getDepth(root.right)

            # If any child tree is unbalanced, return right away
            if left == -1 or right == -1:
                return -1

            # If this tree is unbalanced, return -1
            if abs(left - right) > 1:
                return -1

            # Return normal max depth of current tree
            return max(left, right) + 1

        return getDepth(root) != -1
