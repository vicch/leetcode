"""
Typical DFS problem: for each node, check if its value >= the largest value between it and the root, then pass the new
largest value down to its children.

Time: O(n)
Space: O(m), m = tree depth, for recursion call stack
"""
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def goodNodes(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """

        def dfs(node, maxval):
            if not node:
                return 0

            maxval = max(maxval, node.val)

            # If current value is not equal to the new max value, then it must be smaller than the original max value.
            return int(node.val == maxval) + dfs(node.left, maxval) + dfs(node.right, maxval)
        
        return dfs(root, float('-inf'))
