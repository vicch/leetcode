"""
The question is asking for the maximum number of concurrent meetings. When a meeting starts, the number of other
meetings that haven't finished, i.e. the number of meeting with ending time larger than its start start, is equal to
the number of concurrent meetings of this meeting.

Naturally to reduce unnecessary check, we should iterate the meetings by their starting time in ascending order, and
keep a list of previous meetings' end times. The list should prune all end times that are past when this meeting starts.
Then this meeting's end time is pushed to the list.

As the meeting end times aren't necessarily sorted, to be able to iterate the list of end times in ascending order
while inserting and removing elements, it's natrual to use a min heap.

Time: O(nlogn), sorting is O(nlogn) already, and each meeting will be pushed to heap at least once, and popped at most
once, so O(logn) * n * 2, overall it's O(nlogn)
Space: O(n)
"""
class Solution(object):
    def minMeetingRooms(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: int
        """
        intervals.sort(key=lambda i: i[0])
        endtimes = []
        maxconcurrent = 0
        
        for i in intervals:
            while len(endtimes) > 0 and endtimes[0] <= i[0]:
                heapq.heappop(endtimes)
            heapq.heappush(endtimes, i[1])
            maxconcurrent = max(len(endtimes), maxconcurrent)
    
        return maxconcurrent
