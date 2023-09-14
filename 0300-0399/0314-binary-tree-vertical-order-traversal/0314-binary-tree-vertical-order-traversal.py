"""
Consider manually build the result while BFS the tree, each left/right node is in the column -1/+1 of the root node, so
it's easy to know which column array the value should be inserted into. But it's hard to know how many column arrays
there will be, i.e. the width of the tree, in the beginning.

It is one option to get the width first, then init the column arrays in one go. Another option is to expand the list of
column arrays in the same BFS travesal, which can be done by keeping the current left/right-most columns, and each time
the boundaries are exceeded, append/prepend an empty column array to the list, and update the left/right-most columns.
The offset of the column array for current node can be computed with "node_col - left_col".

Time: O(n), each node is traversed once
Space: O(w), width of the tree, for a full binary tree it can be O(n), as the width is n/2
"""
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def verticalOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if not root:
            return []

        result = collections.deque([[]])
        queue = collections.deque([(root, 0)])
        left = right = 0

        while queue:
            node, col = queue.popleft()
            if not node:
                continue

            if col < left:
                result.appendleft([])
                left = col
            elif col > right:
                result.append([])
                right = col
            
            result[col - left].append(node.val)

            queue.append((node.left, col - 1))
            queue.append((node.right, col + 1))

        return result
