"""
BFS approach: the goal is to find the first leaf node when BFS traversing a tree. Just do normal BFS traversal while
maintaining current depth, and check for the first node that has no child nodes, i.e. it's a leaf node.
"""

class Solution(object):
    def minDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0

        queue, depth = [root], 0

        while queue:
            depth += 1
            nextQueue = []

            for node in queue:
                # For the first node that has no left or right node (i.e. a leaf node), return current depth
                if not node.left and not node.right:
                    return depth

                if node.left:
                    nextQueue.append(node.left)
                if node.right:
                    nextQueue.append(node.right)

            # Swap to nodes queue of next level
            queue = nextQueue
