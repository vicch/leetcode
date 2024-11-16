"""
Brute-force solution: collect and sort all node values, then create a new linked list with the sorted values.

If the nodes contain more data and are expensive to re-create, we can sort a list[(nodeField, nodeRef)] by the field value, then chain up the
node refs into a new list.

Time complexity:
- O(NlogN), N = number of nodes, for sorting.

Space complexity:
- O(N), for lists.
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
        # Collect all values in all lists to a single list
        values = []
        for l in lists:
            while l:
                values.append(l.val)
                l = l.next

        # Sort the values
        values.sort()

        # Create a dummy node before the result list
        pointer = dummy = ListNode(0)
        for v in values:
            # Attach values as nodes to the list
            pointer.next = ListNode(v)
            pointer = pointer.next

        return dummy.next
