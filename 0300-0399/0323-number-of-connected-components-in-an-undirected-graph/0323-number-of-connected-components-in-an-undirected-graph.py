"""
[NEED_REVIEW]

A typical union find problem. After union all connected nodes via the edges, iterate the nodes and find the number of different roots, which is
equal to the number of components in the graph.

The criteria of choosing root when unionizing 2 components, can be either the higher or the lower root of the components.

Time complexity:
- O(E * a(n) + N), for union operations and node traversal, a(n) is inverse Ackermann function which is nearly constant.

Space complexity:
- O(N), for union find internal storage of parent per node.
"""
class UnionFind(object):
    def __init__(self, n):
        # Init each node as its own parent.
        self.parent = list(range(n))
    
    def find(self, x):
        if self.parent[x] != x:
            # Path compression.
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    
    def union(self, x, y):
        rootX = self.find(x)
        rootY = self.find(y)
        
        if rootX == rootY:
            return
        
        # Choosing lower node as root.
        if rootX < rootY:
            self.parent[rootY] = rootX
        else:
            self.parent[rootX] = rootY

class Solution(object):
    def countComponents(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: int
        """
        uf = UnionFind(n)
        for x, y in edges:
            uf.union(x, y)
        
        roots = set()
        for x in range(n):
            roots.add(uf.find(x))

        return len(roots)
