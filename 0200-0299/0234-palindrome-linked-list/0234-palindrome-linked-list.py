"""
For O(1) space and O(n) time, the only way is to reverse half of the list, and compare its the 2 halves are equal.

Reversing a list is essentially building a new list backwards, by taking nodes off the head of the old list, and attach
to the head of the new list.

To find the middle location of the original list, use fast and slow pointers.
"""
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """

        def reverse(head):
            """
            Reverse given list and return new head.
            """

            # Init head of the new list.
            newHead = None

            while head:
                # Take head of old list and attach to head of new list.
                node = head
                head = head.next
                node.next = newHead
                newHead = node

            return newHead

        def isEqual(head, tail):
            # If the original list has even number of nodes, the last node of the head list will point to the last node
            # of the tail list, which means the head list has one more node that should be ignored. The fast and slow
            # pointers already guarantee that the head list has at most one more node in this case, so just checking if
            # it reaches the end of the tail list is enough.
            while tail:
                if head.val != tail.val:
                    return False
                head = head.next
                tail = tail.next
            return True

        if not head:
            return False
        if not head.next:
            return True
        
        # The slow pointer points to the start of the later half when fast pointer reaches the end.
        fast = slow = head
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next

        tail = reverse(slow)

        return isEqual(head, tail)
