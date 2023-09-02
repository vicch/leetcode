"""
Consider the case if all meetings don't overlap, then when sorting the meeting by starting time, each subsequent
meeting's starting time is the same or after the precendent meeting's ending time. If any pair of adjacent meetings
don't fulfill this condition, there is at least one overlapping.

Time: O(nlogn) for sorting
Space: O(1)
"""
class Solution(object):
    def canAttendMeetings(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: bool
        """
        if len(intervals) < 2:
            return True

        intervals.sort(key=lambda i: i[0])
        for i in range(1, len(intervals)):
            if intervals[i-1][1] > intervals[i][0]:
                return False
        return True
