"""
Typical heap use case. Store the top K elements in heap, with the top being the smallest, and maintain the size at K
while iterating the array.

Time: O(nlogk)
Space: O(k)
"""
class Solution(object):
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        heap = []
        for n in nums:
            if len(heap) < k or n > heap[0]:
                heapq.heappush(heap, n)
            if len(heap) > k:
                heapq.heappop(heap)
        return heap[0]
