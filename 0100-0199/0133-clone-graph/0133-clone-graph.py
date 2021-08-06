"""
DFS approach: copy each node, then copy its neighbours recursively. Store all copied nodes in hash map for lookup, use
node values as keys because they are unique globally.
"""
"""
# Definition for a Node.
class Node(object):
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""
class Solution(object):
    def cloneGraph(self, node):
        """
        :type node: Node
        :rtype: Node
        """
        # Cache of node values mapping to node objects
        cache = {}

        def deepCopy(node):
            if not node:
                return None

            # Cache lookup
            if node.val in cache:
                return cache[node.val]

            copy = Node(node.val)
            # Must insert cache before copying neighbors, otherwise it results in infinite recursions (deadlock)
            cache[node.val] = copy

            # Copy neighbors recursively
            for n in node.neighbors:
                copy.neighbors.append(deepCopy(n))

            return copy

        return deepCopy(node)
