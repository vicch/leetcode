"""
A rather annoying pointer handling problem. Can be simplified by abstracting out the core operations:
- Checking if a node is the head of duplicate list, i.e. if its value is equal to its next node.
- Find the next node that is un-equal to a given head node.
"""
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        def findNext(head):
            # It's always called with hasDup(head) == True, so there is no need to validate again.
            i = head.next
            # Traverse till the end or a node with different value is found.
            while i and i.val == head.val:
                i = i.next
            return i

        def hasDup(head):
            return head and head.next and head.val == head.next.val

        if not head or not head.next:
            return head
        
        dummy = ListNode(0, head)
        i = dummy

        while i:
            if hasDup(i.next):
                # If next node has duplicates, find the next node that is not a duplicate to it, and link current node
                # to it, to bypass the duplicate node, but don't move the slow pointer.
                i.next = findNext(i.next)
            else:
                # If next node doesn't have duplicate, move the slow pointer.
                i = i.next

        return dummy.next
