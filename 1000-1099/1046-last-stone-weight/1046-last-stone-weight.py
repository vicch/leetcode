"""
The problem is essentially to constantly pop top 2 elements from a list, and push the result back to it, till there is
zero or one element left. For such top K problem, it's natural to use heap.
"""
class Solution(object):
    def lastStoneWeight(self, stones):
        """
        :type stones: List[int]
        :rtype: int
        """
        # heapq keeps min heap, so negate the values to serve as max heap.
        heap = [-s for s in stones]
        heapq.heapify(heap)

        while len(heap) > 1:
            x = heapq.heappop(heap)
            y = heapq.heappop(heap)
            if x == y:
                continue
            else:
                heapq.heappush(heap, x - y)
        
        return -heap[0] if len(heap) > 0 else 0
