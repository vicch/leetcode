"""
Use 2 pointers:

- Fast pointer moves forward 2 nodes per cycle.
- Slow pointer moves forward 1 node per cycle.

If there is a cycle in the list, the 2 pointer must point to the same node at some point. Otherwise the fast point will
reach the end first.
"""
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        fast, slow = head, head

        # If fast pointer hasn't reached the end yet, slow pointer mustn't have reached the end either, so only checking
        # fast pointer is enough
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
            if fast == slow:
                return True

        return False
