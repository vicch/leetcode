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

        # Think of the tree as a single sequence of nodes populating from left to on for each row. An empty node can
        # appear on any position, but as long as there is one empty node, there shouldn't be any other non-empty node
        # after it.

        reachedEnd = False
        currRow = [root]

        while currRow:
            nextRow = []
            for n in currRow:
                # If this is an empty node, it has reached the end of the tree.
                if not n:
                    reachedEnd = True
                    continue
                # If there is a non-empty node after any empty node, it's not a complete tree.
                if reachedEnd:
                    return False
                # Populate nodes of next row
                nextRow.append(n.left)
                nextRow.append(n.right)
            currRow = nextRow

        return True
