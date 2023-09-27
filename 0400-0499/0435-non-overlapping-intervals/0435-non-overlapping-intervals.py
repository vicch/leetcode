"""
Assuming there are already n non-overlapping intervals, and the ending time of last interval is x. Now for interval n+1,
if its starting time >= x, then there is no overlapping and it can be kept. Otherwise either the current last interval
or the new one should be removed.

To maximize the number of intervals to keep, the collective largest ending time at any point should be as small as
possible. So when there is overlapping, the interval with smaller ending time should be kept.

If all intervals have been sorted by ending time already, then we know interval n+1's ending time is larger than
preceding intervals, so it should be removed.

Time: O(nlogn) for sorting
Space: O(1) if not considering sorting
"""
class Solution(object):
    def eraseOverlapIntervals(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: int
        """
        intervals.sort(key=lambda x: x[1])
        
        remove = 0
        border = float('-inf')

        for x, y in intervals:
            # Interval overlaps with kept intervals, and needs to be removed.
            if x < border:
                remove += 1
            # Interval can be kept, and refresh right border.
            else:
                border = y
        
        return remove
