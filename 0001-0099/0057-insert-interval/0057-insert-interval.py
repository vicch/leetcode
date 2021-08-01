"""
If the new interval is overlapped with any existing interval, they will merge. Otherwise the existing interval remains
unchanged. So the intervals at the end will be 3 parts:

- Existing intervals on left side of the new interval.
- The expanded new interval merged with overlapping intervals.
- Existing intervals on right side of the new interval.
"""
class Solution(object):
    def insert(self, intervals, new):
        """
        :type intervals: List[List[int]]
        :type new: List[int]
        :rtype: List[List[int]]
        """
        left = []
        right = []

        for i in intervals:
            if i[1] < new[0]:
                left.append(i)
            elif i[0] > new[1]:
                right.append(i)
            else:
                # Expand the new interval with current interval
                new[0] = min(i[0], new[0])
                new[1] = max(i[1], new[1])

        return left + [new] + right
