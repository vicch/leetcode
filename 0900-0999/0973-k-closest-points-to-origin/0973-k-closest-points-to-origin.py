"""
A naive solution is sorting all points via custom comparator, which has O(NlogN) complexity.

A better solution is to use heap to maintain the top K points while traversing all points, which
has O(NlogK) complexity.

Time complexity:
- O(NlogK), for heap operations per point.

Space complexity:
- O(K), for the heap.
"""
class Solution(object):
    def kClosest(self, points, k):
        """
        :type points: List[List[int]]
        :type k: int
        :rtype: List[List[int]]
        """
        heap = []

        for x, y in points:
            # Don't need to get square root as it doesn't affect comparison.
            dist = x**2 + y**2

            # Maintain a max heap via negative values.
            heapq.heappush(heap, (-dist, [x, y]))

            # Always keep K candidates in the heap, and remove disqualified points.
            if len(heap) > k:
                heapq.heappop(heap)
        
        return [p[1] for p in heap]
