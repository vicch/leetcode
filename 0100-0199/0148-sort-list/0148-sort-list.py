"""
Performant sorting algorithms mostly involve "divide and conquer". For a list of discrete numbers that can be accessed
randomly, this problem can just be a quick sort or merge sort. For a linked list, the swapping of values needs to be
done in place, via re-arranging the links between the nodes, to reduce space consumption. In terms of "dividing", it
can be done by finding the mid node, via fast and slow pointers.

- Time complexity: O(nlogn) as merge sort (with better worst-case performance)
- Space complexity: O(1) as sorting in place
"""
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def sortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head or not head.next:
            return head

        mid = self.getMid(head)
        left = self.sortList(head)
        right = self.sortList(mid)

        return self.merge(left, right)

    def getMid(self, head):
        slow, fast = head, head

        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next

        mid = slow.next
        # This is important: the list is broken in half after the mid node, for easier handling.
        slow.next = None

        return mid

    def merge(self, l1, l2):
        if not l1:
            return l2
        if not l2:
            return l1

        dummy = ListNode(0)
        curr = dummy

        while l1 and l2:
            if l1.val <= l2.val:
                curr.next = l1
                l1 = l1.next
            else:
                curr.next = l2
                l2 = l2.next
            curr = curr.next

        # Attach remaining nodes
        if l1:
            curr.next = l1
        elif l2:
            curr.next = l2

        return dummy.next
