"""
Typical 2 pointer problem: fast pointer skips all dups to the number pointed by slow pointer, and on reaching the next
different value, link up the nodes referenced by the 2 pointers, then move forward.
"""

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head or not head.next:
            return head

        p, q = head, head.next

        while q:
            # If 2 pointers have different values, link up and move slow pointer forward
            if p.val != q.val:
                p.next, p = q, q
            # Fast pointer always move forward
            q = q.next

        # Slow pointer always stops on the last non-dup number, truncate the list here
        p.next = None

        return head
