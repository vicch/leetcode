"""
This is solvable with Kadane's Algorithm.

Find the DP factor: suppose we have the max of all sub-arrays that end on a[n] which is a[x:n], then for max-array that
ends on a[n+1], it's either extending a[x:n] to a[x:n+1], or just a[n+1] itself.

Then with the local max that ends on each individual element, maintain a global max. At the end, the global max is the
result.
"""
class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        localmax, globalmax = nums[0], nums[0]
        for n in nums[1:]:
        	# Either the current sub-array continues, or a new sub-array with bigger sum starts
            localmax = max(localmax + n, n)
            globalmax = max(globalmax, localmax)
        return globalmax
