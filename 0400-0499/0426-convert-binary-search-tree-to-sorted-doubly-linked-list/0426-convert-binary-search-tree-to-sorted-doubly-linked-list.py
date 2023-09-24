"""
A natural recusion approach: for each root node, convert its left and right child trees to lists, then attach the lists
into one and return to upper level. 

There is a key operation of attaching 2 double linked lists with pointers to their head nodes, and return pointer to
head node of the first list after attachment.

Time: O(n), each node is processed one or more times as the root node and head/tail node.
Space: O(logn) in best case of balanced tree, O(n) in worst case.
"""
"""
# Definition for a Node.
class Node(object):
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
"""
class Solution(object):
    def treeToDoublyList(self, root):
        """
        :type root: Node
        :rtype: Node
        """
        if not root:
            return None

        head, left, right = root, root.left, root.right
        head.left, head.right = head, head

        if left:
            leftHead = self.treeToDoublyList(left)
            head = self._attatchLists(leftHead, head)

        if right:
            rightHead = self.treeToDoublyList(right)
            head = self._attatchLists(head, rightHead)

        return head

    def _attatchLists(self, head1, head2):
        tail1, tail2 = head1.left, head2.left
        tail1.right, head2.left = head2, tail1
        head1.left, tail2.right = tail2, head1
        return head1
