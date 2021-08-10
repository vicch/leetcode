"""
Elements in a linked list cannot be directly accessed via index. But recursion similar to #108 Convert Sorted Array to
Binary Search Tree can still simulate the DFS on a linked list, by using a pointer starts at the head, and moves
forward one element for every left side recursion that returns.

For example, array [-10, -3, 0, 5, 9]

1st level:       range = [0, 4], root index = 2, pointer = -10, left = [0, 1],  right = [3, 4]
  2nd level:     range = [0, 1], root index = 1, pointer = -10, left = [0, 0],  right = [1, 1]
    3rd level:   range = [0, 0], root index = 0, pointer = -10, left = [0, -1], right = [1, 0]
      4th level: range = [0, -1], return empty node
    3rd level:   root val = -10, pointer = -3 (moves forward)
      4th level: range = [1, 0], return empty node
    3rd level:   root left = empty, root right = empty, return
  2nd level:     root val = -3, pointer = 0 (moves forward)
    3rd level:   range = [1, 1], root index = 1, pointer = 0, left = [1, 0], right = [2, 1]
    ...
"""

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def sortedListToBST(self, head):
        """
        :type head: ListNode
        :rtype: TreeNode
        """
        self.pointer = head

        def buildTree(l, r):
            if l > r:
                return None

            m = (l + r + 1) // 2

            left = buildTree(l, m-1)

            root = TreeNode(self.pointer.val)
            # Move pointer to next inorder node
            self.pointer = self.pointer.next

            right = buildTree(m+1, r)

            # Assemble the tree
            root.left, root.right = left, right

            return root

        # Count number of elements in the linked list
        length = 0
        while head:
            length += 1
            head = head.next

        return buildTree(0, length - 1)
