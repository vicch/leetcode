"""
Merging K sorted lists can be done by merging pairs of lists using the same method as #21 Merge Two Sorted Lists. After
merging all pairs, the resulting lists can then be merged in pairs again. Each round halves the number of lists, till
there is only one left.

Lists:   0 1 2 3 4 5 6 7
Round 1: 0 1 2 3         // Lists 0 and 7 merge into 0, 1 and 6 merge into 1, etc.
Round 2: 0 1             // Lists 0 and 3 merge into 0, 1 and 2 merge into 1
Round 3: 0               // Lists 0 and 1 merge into 0
"""
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """

        def mergeTwoLists(l1, l2):
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
            pointer.next = l1 or l2

            # Next of dummy node is head of result list
            return dummy.next

        if not lists:
            return None

        l, r = 0, len(lists) - 1
        while r > 0:
            # Merge 2 lists on both ends into the left list
            lists[l] = mergeTwoLists(lists[l], lists[r])
            l += 1
            r -= 1
            # After meeting at the middle, reset left list to the start to continue merging the left half of lists
            if l >= r:
                l = 0

        return lists[0]
