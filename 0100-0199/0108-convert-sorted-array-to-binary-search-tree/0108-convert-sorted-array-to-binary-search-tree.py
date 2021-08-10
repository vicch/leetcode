"""
By definition, the BST should be built with the middle element as root, then sub-trees built with the left and right
half of sub-arrays recursively.
"""

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def sortedArrayToBST(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        def buildTree(l, r):
            # Check recursion boundary
            if l > r:
                return None

            # (l + r) // 2 is OK as well, just round up the middle index to be exactly as the official solution
            m = (l + r + 1) // 2
            # Return root node with child nodes recursively built by passing the left and right ranges
            return TreeNode(nums[m], buildTree(l, m-1), buildTree(m+1, r))

        return buildTree(0, len(nums)-1)
