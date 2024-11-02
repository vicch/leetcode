"""
The edges form a tree if:

- All nodes are connected to at least one other node.
- All nodes are connected to a single graph, i.e. all nodes can be visited by DFS from any node in the graph.
- There is no cycle.

To check condition 1 and 2, we can build the adjacency array and DFS the graph, and check if all nodes are reachable.

To check condition 3, we can memorize the visited nodes, and return False if it's visited for a second time. There is a trick to pass the prev
node down the DFS invocation to avoid going back the same edge where the DFS comes from.

Another trick is to return early by simply checking the number of edges, because for a valid tree, each node has a single edge connects to its
parent node except the root, thus there must be exactly N-1 edges.

Time complexity:
- O(N), because each edge is converted and visited once, and edge count equals to N-1.

Space complexity:
- O(N), for adjacency array.
"""
class Solution(object):
    def validTree(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: bool
        """
        # Pruning via graph theory
        if len(edges) != n - 1:
            return False

        # Convert edges to graph map
        graph = [[] for _ in range(n)]
        for x, y in edges:
            graph[x].append(y)
            graph[y].append(x)
        
        visited = set()

        def dfs(i, prev):
            # If a node is visited twice, there is a loop.
            if i in visited:
                return False
    
            visited.add(i)

            # DFS connected nodes.
            for j in graph[i]:
                # Important: skip reverse revisiting to not trigger the loop detection via the same edge.
                if j == prev:
                    continue
                if not dfs(j, i):
                    return False

            return True
        
        # All nodes were visited while no loop was found.
        return dfs(0, -1) and len(visited) == n
