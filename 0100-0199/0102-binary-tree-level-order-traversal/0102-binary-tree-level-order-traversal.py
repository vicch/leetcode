"""
The travesal of each level and its next level and be done via a queue:

- For each node, push its child nodes to the queue, and collect its value.
- When this queue runs out, meaning all nodes of current level are visited, then continue to the next level via the
nodes queue populated in this level.
- Continue till the queue of next level becomes empty.
"""
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if not root:
            return []

        # Init the nodes queue as root
        levels, queue = [], [root]

        # If there are more nodes in the queue (i.e. there is next level)
        while queue:
            nextQueue, level = [], []
            for node in queue:
                level.append(node.val)

                # Push left and right nodes to the queue for next level
                if node.left:
                    nextQueue.append(node.left)
                if node.right:
                    nextQueue.append(node.right)

            # Swap nodes queue to next level
            queue = nextQueue
            levels.append(level)

        return levels
