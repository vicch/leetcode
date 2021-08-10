"""
Simply add up corresponding digits from the 2 lists and create nodes to the new list. Trick part is to maintain the
carry over value to next digit, and empty check for pointers to the 2 lists.
"""

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        # Dummy node before first digit for simple handling
        dummy = ListNode()

        # Init lowest digit and carry over digit
        p, carry = dummy, 0

        # Continue till there is more digit or carry over digit
        while l1 or l2 or carry:
            sum = carry + (l1.val if l1 else 0) + (l2.val if l2 else 0)
            carry = sum // 10

            # Append digit and move forward
            p.next = ListNode(sum % 10)
            p = p.next

            if l1:
                l1 = l1.next
            if l2:
                l2 = l2.next

        return dummy.next
