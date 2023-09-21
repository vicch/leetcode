"""
It might appear that binary search is needed to find the low/high values, and collect node values on the path from root
to the nodes. But this won't be able to visit all nodes within the range.

It's actually a recursive problem:
rangeSum(root, low, high) = rangeSum(root.left, low, high) + rangeSum(root.left, low, high) + root.val

Branches that are out of range can be cut, e.g. if root is already smaller than low, then all values on left branch
will be smaller.

Time: O(n), n being number of nodes, the recursion depth is logn, but the number of nodes to traverse is the number of
nodes within the range
Space: O(n), in worst case of single branch tree
"""
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def rangeSumBST(self, root, low, high):
        """
        :type root: TreeNode
        :type low: int
        :type high: int
        :rtype: int
        """
        if not root:
            return 0
        
        if root.val < low:
            return self.rangeSumBST(root.right, low, high)
        if root.val > high:
            return self.rangeSumBST(root.left, low, high)
        
        return root.val + self.rangeSumBST(root.left, low, root.val) + self.rangeSumBST(root.right, root.val, high)
