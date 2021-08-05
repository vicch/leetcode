"""
BFS approach is similar to #102 Binary Tree Level Order Traversal, use a queue to store nodes of each level. While
(de)serializing the nodes of each level, push their child nodes to another queue, then swap to that queue at the end
of current level, and continue to process next queue.
"""
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.

        :type root: TreeNode
        :rtype: str
        """
        if not root:
            return [None]

        values, queue = [], [root]

        while queue:
            nextQueue = []
            for node in queue:
                if node:
                    nextQueue.append(node.left)
                    nextQueue.append(node.right)
                # Append value of current node accordingly
                values.append(node.val if node else None)

            # Swap to next level
            queue = nextQueue

        return values


    def deserialize(self, data):
        """Decodes your encoded data to tree.

        :type data: str
        :rtype: TreeNode
        """
        if len(data) == 0 or data[0] is None:
            return None

        root = TreeNode(data[0])

        # Init pointer and node queue
        i, queue = 1, [root]

        while queue:
            nextQueue = []
            for node in queue:
                # Create left node if value is non-empty
                if data[i] is not None:
                    node.left = TreeNode(data[i])
                    nextQueue.append(node.left)

                # Advance pointer
                i += 1
                if i == len(data):
                    break

                # Create right node if value is non-empty
                if data[i] is not None:
                    node.right = TreeNode(data[i])
                    nextQueue.append(node.right)

                # Advance pointer
                i += 1
                if i == len(data):
                    break

            # Swap queue to next level
            queue = nextQueue

        return root
