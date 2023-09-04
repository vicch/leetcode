"""
BFS approach: cache mapping from original node values (because values are unique) to cloned nodes and serve as visited
lookup. Push unvisited nodes to queue and visit till queue is empty. For the visit, iterate the node's neighbors, for
any unvisited neighbor, push it to queue to visit later, and create an empty cloned node and store in cache. Update the
neighbors of the cloned node.

Time: O(n + m), n = nodes, m = edges
Space: O(n) for the cache, the queue also takes O(w) of the graph's width.
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
        self.queue = collections.deque([])

    def cloneGraph(self, node):
        """
        :type node: Node
        :rtype: Node
        """
        if not node:
            return None

        # Init queue
        self.cache[node.val] = Node(node.val, [])
        self.queue.append(node)

        while self.queue:
            visit = self.queue.popleft()
            # Iterate neighbors of node being visited.
            for n in visit.neighbors:
                # Clone neighbor node if not cloned yet.
                if n.val not in self.cache:
                    self.cache[n.val] = Node(n.val, [])
                    self.queue.append(n)
                # Update neighbors list of the matching node to the node being visited.
                self.cache[visit.val].neighbors.append(self.cache[n.val])

        return self.cache[node.val]
