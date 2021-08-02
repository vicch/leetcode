"""
Use 2 pointers that are n nodes apart. When the fast pointer reaches the end, the slow pointer will point to the node to
be removed.

Edge case to consider is when the first node is to be removed. A dummy node can point to the head to support this case.
"""
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        # Dummy node point to head
        dummy = ListNode(0)
        dummy.next = head
        fast = slow = dummy

        # Move fast pointer n times
        for _ in range(n):
            fast = fast.next

        # Move both pointers till fast pointer reaches the end
        while fast.next:
            fast, slow = fast.next, slow.next

        # Re-wire the next node of slow pointer
        slow.next = slow.next.next

        return dummy.next