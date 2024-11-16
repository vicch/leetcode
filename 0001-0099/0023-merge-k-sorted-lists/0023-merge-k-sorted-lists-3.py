"""
[NEED_REVIEW]

The solution can be thought as:

1. Maintain one pointer per list starting from the head.
2. Constantly pick the one currently pointing to the node with smallest value.
3. Add that node to the merged list, then move the pointer to its next node in the sub-list.
4. Continue till all lists are traversed.

The key is to find the one node with smallest value at any time, which is essentially finding the min/max value of a list that is constantly
updated, and naturally the use case of a heap (priority queue).

Time complexity:
- O(NlogK), N = total number of nodes, K = number of lists, because each node is pushed and popped once to the heap, which is O(logK).

Space complexity:
- O(N + K), for the final list and the heap.
"""
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[Optional[ListNode]]
        :rtype: Optional[ListNode]
        """
        heap = []
        for l in lists:
            # Handle empty list
            if l:
                heapq.heappush(heap, (l.val, l))
        
        dummy = ListNode()
        pointer = dummy

        while heap:
            # Pop next node and extend merged list.
            _, node = heapq.heappop(heap)
            pointer.next = node
            pointer = pointer.next

            # Push following node if exits.
            if node.next:
                heapq.heappush(heap, (node.next.val, node.next))

        return dummy.next
