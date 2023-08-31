"""
Naturally a recursive problem: a balanced tree is recursively balanced, so if any child tree isn't balanced, the
recursive check can pop all the way up and return false.

But if a child tree is balanced, it needs to return its depth to upper level for the balance check.
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
        
        # Returns a tuple, of a boolean indicating if the current tree is balanced, and an int of the tree's depth.
        def checkTree(node):
            if not node:
                return True, 0
            
            # Return early if any child tree is not balanced. The depth is irrelevant in such case, just return 0.
            left = checkTree(node.left)
            if not left[0]:
                return False, 0
            right = checkTree(node.right)
            if not right[0]:
                return False, 0

            # If child trees are balanced, but current tree isn't.
            if abs(left[1] - right[1]) > 1:
                return False, 0

            # If current tree is balanced, return its depth.
            return True, max(left[1], right[1]) + 1

        return checkTree(root)[0]
