"""
For each node that is on the final longest diameter, there are 2 cases:
- The longest diameter passes through its parent.
- The longest diameter doesn't pass through its parent.

We need to recursively check the candidate length each node can contribute to the longest diameter in these 2 cases,
and pass the candidates to the parent node to decide the values to pass further upward.
"""
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def diameterOfBinaryTree(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        
        def getCandidates(node):
            # Leaf nodes has one more level of recursion, return -1 as candidates to compensate this extra level.
            if not node:
                return (-1, -1)

            left = getCandidates(node.left)
            right = getCandidates(node.right)

            # The better diamater to further attach to upper level.
            attachable = max(left[0], right[0]) + 1

            # The non-attachable best diameter is either a non-attachable diamater of child nodes, or one that passes
            # through current node.
            nonAttachable = max(left[1], right[1], left[0] + right[0] + 2)

            return (attachable, nonAttachable)
        
        return max(getCandidates(root))
