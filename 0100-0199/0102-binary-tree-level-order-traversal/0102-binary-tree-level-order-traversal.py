"""
A typical BFS problem, key is to know when it continues to the next level of nodes. This can be achieved by keeping 2
queues for each level:

- One queue of current level nodes, which is drained at the end.
- Another queue for next level nodes, which is swapped to the first queue at the end.

Then for each level, collect the node values and append to the result list.

Time: O(n)
Space: O(n + m), m = diameter of tree, for the BFS queues
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
