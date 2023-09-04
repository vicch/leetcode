"""
DFS approach: copy each node, then copy its neighbours recursively. Store all copied nodes in hash map for lookup, use
node values as keys because they are unique globally.

Time: O(n + m), n = nodes, m = edges
Space: O(n) for the cache, the call stack also takes O(h) of the graph's height
"""
"""
# Definition for a Node.
class Node(object):
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""
class Solution(object):
    def __init__(self):
        self.cache = {}

    def _dfs(self, node):
        if not node:
            return None
        
        if node.val in self.cache:
            return self.cache[node.val]
        
        clone = Node(node.val, [])
        self.cache[node.val] = clone

        for n in node.neighbors:
            clone.neighbors.append(self._dfs(n))

        return clone

    def cloneGraph(self, node):
        """
        :type node: Node
        :rtype: Node
        """
        return self._dfs(node)
