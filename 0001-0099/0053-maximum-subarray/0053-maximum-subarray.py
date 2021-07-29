class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        """
        Consider all the sub-arrays, the goal to find the one with the largest sum. For each number in the array, it
        either A) continues the sub-array up to its last element to make the sub-array's sum bigger, or B) starts
        another sub-array with a bigger sum on its own.

        As the iteration continues, maintain the current max sum of all sub-arrays processed so far. At the end of the
        array, it will be the max sum of all sub-arrays.
        """

        sub_sum, max_sum = nums[0], nums[0]
        for n in nums[1:]:
        	# Either the current sub-array continues, or a new sub-array with bigger sum starts
            sub_sum = max(sub_sum + n, n)
            max_sum = max(max_sum, sub_sum)
        return max_sum