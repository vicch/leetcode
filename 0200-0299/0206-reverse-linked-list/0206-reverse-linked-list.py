"""
It's essentially building the reverse list by popping nodes from the original list and prepend it to the new list. Keep
two pointers at the head of the original and reverse list, and init the reverse list as empty. Keep popping and
prepending till the end of original list.

Time: O(n)
Space: O(1)
"""
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        prev = None
        while head:
            next, head.next = head.next, prev
            prev, head = head, next
        return prev
