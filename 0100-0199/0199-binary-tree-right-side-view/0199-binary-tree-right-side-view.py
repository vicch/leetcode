"""
Naturally a BFS problem: collect nodes of each level in a queue, then the last one in the queue is the right-most. Then
iterate all nodes in the queue to add nodes of next level.
"""
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def rightSideView(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if not root:
            return []

        view = []

        queue = [root]
        while len(queue) > 0:
            view.append(queue[-1].val)

            nextqueue = []
            for node in queue:
                if node.left:
                    nextqueue.append(node.left)
                if node.right:
                    nextqueue.append(node.right)

            queue = nextqueue

        return view
