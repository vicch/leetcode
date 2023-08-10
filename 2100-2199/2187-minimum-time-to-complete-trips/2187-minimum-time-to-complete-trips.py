"""
To find a certain value of quantity in a range, the natural way to optimize is via binary search: with upper boundary
and lower boundary of the travel time, find the value that is just enough to complete the trips, by calculate the number
of trips for the middle value and narrow down to the proper half.

Sorting the input times in the beginning would appear to speed up th calculations (because we can stop when the
trip < 1 for a certain bus with the given travel time), but actually it's faster to not sort the times.
"""
class Solution(object):
    def minimumTime(self, time, totalTrips):
        """
        :type time: List[int]
        :type totalTrips: int
        :rtype: int
        """
        def countTrips(tripTime):
            return sum([tripTime // t for t in time])

        # Upper bound of travel time is when all trips are done by the bus with minimum trip time
        l, r = 1, min(time) * totalTrips

        while l < r:
            m = (l + r) // 2
            if countTrips(m) >= totalTrips:
                r = m
            else:
                l = m + 1

        return l
