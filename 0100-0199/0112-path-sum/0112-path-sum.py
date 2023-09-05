"""
Simple DFS, maintain target sum and check child trees against the target, check if target reaches 0 at the bottom.

Trick is if there is only one child node, that branch is the only option, empty node doesn't count as leaf.

Time: O(n), because each node is visited at most once.
Space: O(logn) for recursion, but O(n) in worst case of completely unbalanced tree.
"""
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def _dfs(self, root, target):
        if not root:
            return target == 0
        
        newTarget = target - root.val

        # If there are both left and right node, check both child trees.
        if root.left and root.right:
            return self._dfs(root.left, newTarget) or self._dfs(root.right, newTarget)
        
        # Otherwise only check the side that has node. If there are no child nodes, it doesn't matter which one is
        # checked as the next level is bottom anyway.
        return self._dfs(root.left, newTarget) if root.left else self._dfs(root.right, newTarget)

    def hasPathSum(self, root, targetSum):
        """
        :type root: TreeNode
        :type targetSum: int
        :rtype: bool
        """
        if not root:
            return False

        return self._dfs(root, targetSum)
