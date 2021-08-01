"""
Similar to #56 Merge Intervals, if intervals i and j (assuming already sorted by left values) overlap, then it must be
true that i[1] > j[0] (i[1] == j[0] is not considered overlapping in this problem).

When 2 intervals overlap, then one of them must be removed. Globally it's more beneficial to remove the interval whose
right value is larger, because by removing it, the remaining intervals have more "room to stretch" before overlapping
happens.

So by keeping track of the right-most value of all intervals being kept (i.e. not overlapping with each other) so far,
and iterate the intervals from left to right and remove if necessary. Keep track of the number of intervals being
removed. Then at the end return this value.
"""
class Solution(object):
    def eraseOverlapIntervals(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: int
        """
        intervals.sort(key=lambda pair: pair[0])

        removed = 0
        # Edge init to the right value of first interval
        edge = intervals[0][1]

        for i in range(1, len(intervals)):
            # If current interval overlaps with the edge of the currently kept intervals
            if edge > intervals[i][0]:
                edge = min(edge, intervals[i][1])
                # Either this interval or the last kept interval needs to be removed, the most valuable one to remove is
                # one whose right value is larger, therefore the edge after removal is the smaller right value of the 2.
                removed += 1
            else:
                # If not overlapping, this interval is kept, edge becomes right value of this interval (it must be
                # bigger than the previous edge, otherwise there would be overlapping).
                edge = intervals[i][1]

        return removed
