"""
Consider 2 intervals, assuming sorted by the left values, if they can be merged, they must fulfill i[1] >= j[0], and the
merged interval is [i[0], max(i[1], j[1])].

So by sorting the intervals with left values, then iterate the intervals and merge overlapping ones along the way, the
result will contain all intervals with the mergable ones merged.
"""
class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: List[List[int]]
        """
        # Sort all intervals by left values
        intervals.sort(key=lambda pair: pair[0])
        
        merged = []
        for i in range(len(intervals) - 1):
            # If this interval can be merged with next, merge them and overwrite to the next interval
            if intervals[i][1] >= intervals[i+1][0]:
                intervals[i+1] = [intervals[i][0], max(intervals[i][1], intervals[i+1][1])]
            # If the interval cannot be merged any more, push it to the final intervals
            else:
                merged.append(intervals[i])

        # Push the last interval
        merged.append(intervals[-1])

        return merged
