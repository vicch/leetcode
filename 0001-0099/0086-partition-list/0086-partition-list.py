"""
Iterate the input list, and build 2 lists with the nodes belonging to different partitions on the input list. Attach
the 2 lists at the end and return head of the first list.
"""

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def partition(self, head, x):
        """
        :type head: ListNode
        :type x: int
        :rtype: ListNode
        """

        # Create 2 dummy nodes as head of partition lists
        h1, h2 = ListNode(), ListNode()
        p, t1, t2 = head, h1, h2

        while p:
            # Check which partition list this node should be on
            if p.val < x:
                t1.next = ListNode(p.val)
                t1 = t1.next
            else:
                t2.next = ListNode(p.val)
                t2 = t2.next
            p = p.next

        # Link up 2 partition lists
        t1.next = h2.next

        return h1.next
