"""
With the pointer from child to parent, this is essentially finding the intersection of 2 linked lists. The
straightforward solution is to memorize the path from first node to root, and while following the path from second node
to root, check for visited node. The first visited node is their LCA.

Another approach with O(1) space is the two pointer method: each pointer iterates from either given node to the root,
and restart the iteration from the other node. When the two pointers meet, they are pointing to LCA.

Time: O(logn), n being number of nodes, and logn being depth of the tree.
Space: O(logn)
"""
"""
# Definition for a Node.
class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
        self.parent = None
"""
class Solution(object):
    def lowestCommonAncestor(self, p, q):
        """
        :type node: Node
        :rtype: Node
        """
        path = set()
        while p:
            path.add(p)
            p = p.parent
        while q and q not in path:
            q = q.parent
        return q
