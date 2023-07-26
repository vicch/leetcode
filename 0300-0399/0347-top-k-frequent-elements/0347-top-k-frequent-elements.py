"""
It's essentially counting all numbers, then sort the numbers by their associated count, then return the first K. The
O(nlogn) time complexity constraint indicates a normal sorting algorithm as the core.
"""
class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        counts = collections.defaultdict(int)
        for n in nums:
            counts[n] += 1

        # Get sorted tuples (number and count) by the counts
        sortedCounts = sorted(counts.items(), key=lambda item: item[1], reverse=True)

        return [t[0] for t in sortedCounts[:k]]
