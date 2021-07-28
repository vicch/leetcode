# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isCompleteTree(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if not root:
            return True

        level = 0
        nodes = [root]
        reachedBottom = False # Has the traversal reached bottom line already

        while len(nodes) > 0:
            # If has reached bottom line already and there is more nodes, it's not a complete tree
            if reachedBottom:
                return False

            # For any row that is not "complete", it's not a complete tree
            if not self.isCompleteRow(nodes):
                return False

            # If this row is not full, it should be the bottom row (assuming the tree is complete)
            if not self.isFullRow(nodes, level):
                reachedBottom = True

            # Read nodes of next row
            nodes = self.getNextRow(nodes)
            level += 1

        return True

    def isFullRow(self, nodes, level):
        # For row N (root is row 0), it should have 2^N nodes to be a full row
        return len(nodes) == 1 << level

    def isCompleteRow(self, nodes):
        # A complete row contains only non-empty nodes on the left, and empty nodes on the right
        i = 0
        
        # Find the first empty node
        while i < len(nodes) and nodes[i]:
            i += 1

        # All nodes since the first empty node should be empty nodes
        for n in nodes[i:]:
            if n:
                return False

        return True

    def getNextRow(self, nodes):
        nextRow = []
        for n in nodes:
            if n:
                nextRow.append(n.left)
                nextRow.append(n.right)
        return nextRow
