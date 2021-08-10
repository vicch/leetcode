"""
Basically just need careful mutation of pointers and links. Tricky part is to use a dummy node that points to head node
for simple handling:

1. Add dummy node: 0->1->2->3->4
2. Init pointers:  0->1->2->3->4
                   l  r
3. Swap step 1:    0->2->3->4    // l.next = r.next
                   1->2...
4. Swap step 2:    0->2->3->4    // r.next = r.next.next
                   1->3...
5. Swap step 3:    0->2->1->3->4 // l.next.next = r
6. Move pointers:  0->2->1->3->4
                         l  r
"""

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        # Dummy node before head for easy handling
        dummy = ListNode(0, head)

        l, r = dummy, dummy.next
        while r is not None and r.next is not None:
            l.next = r.next
            r.next = r.next.next
            l.next.next = r
            l, r = r, r.next

        return dummy.next
