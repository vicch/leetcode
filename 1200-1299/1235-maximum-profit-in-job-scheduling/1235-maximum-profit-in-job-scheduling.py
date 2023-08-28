"""
A DP problem: for each job, there are 2 choices:
- Either schedule it and cancel all scheduled but conflicting jobs
- Or don't schedule it and keep all scheduled jobs

The choice with overall opmital profit should be taken, then proceed to schedule next job. At the end, return the last
optimal profit after processing all jobs.

The jobs need to sorted by end time in ascending order, and the DP cache contains opmital profit that can be obtained
at each time point. Then to find the optimal profit before a given job starts, binary search can be used to find the
lower bound or equal match of given job's start time in the DP cache.

Time: O(nlogn), sorting is O(nlogn) already, and the binary searches take another n*O(logn)
Space: O(n)
"""
class Solution(object):
    def jobScheduling(self, startTime, endTime, profit):
        """
        :type startTime: List[int]
        :type endTime: List[int]
        :type profit: List[int]
        :rtype: int
        """
        # Find lower bound value: the rightmost value that is equal to or lower than given value.
        # Because the same end time may be appended multiple times into the DP cache, but the rightmost should always
        # be the current optimal.
        def getOptimalTill(profits, time):
            l, r = 0, len(profits) - 1
            while l <= r:
                m = (l + r ) // 2
                if profits[m][0] > time:
                    r = m - 1
                else:
                    l = m + 1
            return profits[r][1]

        jobs = sorted(zip(startTime, endTime, profit), key=lambda t: t[1])
        profits = [(0, 0)]

        for start, end, profit in jobs:
            withJob = getOptimalTill(profits, start) + profit
            withoutJob = profits[-1][1]

            if withJob > withoutJob:
                profits.append((end, withJob))
        
        return profits[-1][1]
