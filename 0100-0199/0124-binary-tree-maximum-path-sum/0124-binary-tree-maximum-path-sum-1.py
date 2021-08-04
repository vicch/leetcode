"""
For any in the tree, in the perspective of its parent node, there are 2 types of max path:

- A path that can be connected to the parent node, i.e. a path that runs through current node and runs down either
branch of current node. Refer to this type as flex path (because it can still extend to parent node).
- A path that cannot be connected to the parent node, i.e. a path that doesn't even pass through current node (the path
is passed up from a child node of current node), or a path that runs both child nodes and current node. Refer to this
type as fixed path (because it cannot extend to parent node anymore).

The max path of each type can be calculated based on the max path of its branches. Then return the max paths of current
node up to parent node. The final result is the larger of these max paths on the root node.
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
        def recursion(node):
            if not node:
                return [None, None]

            l, r = recursion(node.left), recursion(node.right)

            # Fixed max candidates:
            # - Fixed max on either branch
            # - Flex max on either branch (when root value is negative)
            # - Sum of both flex max plus the root
            fixedMax = max(l[0], r[0], l[1], r[1], (l[1] + r[1] + node.val if (l[1] and r[1]) else None))

            # Flex max candidates:
            # - Flex max of either branch (if positive, otherwise 0 is better)
            # Flex max always need to include the current node, because it needs to be able to extend to upper level
            flexMax = max(max(l[1], 0), max(r[1], 0)) + node.val

            return [fixedMax, flexMax]

        return max(recursion(root))
