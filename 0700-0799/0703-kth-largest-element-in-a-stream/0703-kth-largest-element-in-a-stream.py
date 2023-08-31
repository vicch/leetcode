"""
Kth largest/smallest element problem typically relates to heap. With a min heap of max size K, every time an element is
pushed to the heap, pop the smallest if the max size is exceeded, then the heap will contain the K largest elements met
so far, and the top is the Kth largest.
"""
class KthLargest(object):

    def __init__(self, k, nums):
        """
        :type k: int
        :type nums: List[int]
        """
        self.k = k
        # Heap's underlying DS is just array, only heap-related operations need to be triggered via heapq methods.
        self.heap = []
        for n in nums:
            self.add(n)

    def add(self, val):
        """
        :type val: int
        :rtype: int
        """
        # Only need to push if the heap isn't full, or if the value is eligible in the heap.
        if len(self.heap) < self.k or val > self.heap[0]:
            heapq.heappush(self.heap, val)

        # Pop if max size is exceeded. It should only exceed by 1 at any point.
        if len(self.heap) > self.k:
            heapq.heappop(self.heap)

        # Access top of the heap just by index 0 of the array.
        return self.heap[0]

# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)
