"""
To get the result list, the process is:

- Break the lists into 2 halves.
- Reverse the 2nd half list (same as #206 Reverse Linked List).
- Merge the 2 lists together.
"""
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def reorderList(self, head):
        """
        :type head: ListNode
        :rtype: None Do not return anything, modify head in-place instead.
        """
        def reverseList(head):
            prev = None
            while head:
                next, head.next = head.next, prev
                prev, head = head, next
            return prev

        fast, slow = head, head
        # When fast pointer reaches the end, slow pointer is at the node before the 1st node of the 2nd half of the
        # list. For a list with odd number of nodes, the 2nd half has 1 less node than the 1st half.
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
        # Break the link between the 1st and 2nd half lists, and move slow pointer to 1st node of 2nd half.
        slow.next, slow = None, slow.next

        # Reverse the 2nd half list.
        head2 = reverseList(slow)

        # Merge the lists together
        i, j = head, head2
        while i and j:
            i.next, i = j, i.next
            j.next, j = i, j.next

        # Head pointer still points to the 1st node.
        return head
