"""
Consider 2 intervals, assuming sorted by the left values, if they can be merged, they must fulfill i[1] >= j[0], and the
merged interval is [i[0], max(i[1], j[1])].

So by sorting the intervals with left values, then iterate the intervals and merge overlapping ones along the way, the
result will contain all intervals with the mergable ones merged.

Time: O(nlogn) for sorting.
Space: O(n) for the merged list.
"""
class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: List[List[int]]
        """
        intervals.sort(key=lambda x: x[0])
        
        # Init with first interval.
        merged = [intervals[0]]

        for x, y in intervals[1:]:
            # If overlapping, merge and extend last interval.
            if x <= merged[-1][1]:
                merged[-1][1] = max(merged[-1][1], y)
            else:
                merged.append([x, y])
        
        return merged
