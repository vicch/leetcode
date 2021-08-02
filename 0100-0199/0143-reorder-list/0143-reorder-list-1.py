"""
Trade space to simplify the process: store all nodes in an array, so they can be accessed via indexes. Then pick nodes
from the start and end in pairs, and link them up as requested, then return the list head.
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
        # Store all nodes in a list
        nodes = []
        p = head
        while p:
            nodes.append(p)
            p = p.next

        # Dummy node points to the head node (after reorder)
        dummy = ListNode(0)
        p = dummy

        for i in range(len(nodes) // 2):
            # Attach nth node from front and nth node from back to the list
            p.next = nodes[i]
            p = p.next
            p.next = nodes[~i]
            p = p.next

        # If the number of nodes is odd, attach the middle node to the list
        if len(nodes) % 2 == 1:
            p.next = nodes[len(nodes) // 2]
            p = p.next

        # End the list to cut cycle
        p.next = None

        return dummy.next
