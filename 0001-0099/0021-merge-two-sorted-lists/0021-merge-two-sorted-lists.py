"""
Build a new list, and attach the next proper node (the node with currently smaller value) to it while iterating the 2
existing lists.

For easier handling and for getting handle of the result list at the end, attach a dummy node to the start of the new
list.
"""
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        # Create new list with dummy node before the first real node
        pointer = dummy = ListNode(0)

        while l1 and l2:
            # If l1 node is smaller, attach it to end of result list
            if l1.val < l2.val:
                pointer.next, l1 = l1, l1.next
            # Otherwise attach l2 node
            else:
                pointer.next, l2 = l2, l2.next
            pointer = pointer.next

        # If there is remaining nodes in either list, attach directly to the end of result list, as there are no more
        # nodes to merge
        pointer.next = l1 or l2

        # Next of dummy node is head of result list
        return dummy.next
