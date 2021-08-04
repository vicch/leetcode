"""
For each node, if it's on the final max path (i.e. a sub-tree), it's either the root of this sub-tree, or a node on the
path of the sub-tree, i.e. the sub-tree extends to its parent node.

By keeping a current global max sum, we can compare if the current node being root can beat the current max sum. Then
return the max sum this node can contribute to the parent node.
"""
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def maxPathSum(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        # Global max sum
        self.maxSum = None

        def visit(node):
            if not node:
                return None

            # If path sum passed from branches is negative, 0 (cut that branch) is a better option
            l = max(visit(node.left), 0)
            r = max(visit(node.right), 0)

            # Check if a sub-tree with current node as root improves the global max sum
            self.maxSum = max(self.maxSum, node.val + l + r)

            # The local max path that runs through current node to parent node
            return max(l, r) + node.val

        visit(root)

        return self.maxSum
