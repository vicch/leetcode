"""
Similar to #198 House Robber, but has 2 cases:

- Rob the first house, then get the max amount without robbing the last house. This is same as non-circle house robbing
by omitting the last house.
- Don't rob the first house, then get the max amount of robbing the last house. This is same as non-circle house robbing
by omitting the first house.

The larger value of the 2 is the optimal result.
"""
class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) < 2:
            return nums[0]

        return max(self.robSub(nums[:-1]), self.robSub(nums[1:]))

    def robSub(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        l = len(nums)
        # DP array is 0-indexed, with index 1 indicating the max value after the 1st house, i.e. nums[0].
        dp = [0] * (l + 1)
        # For the 1st house, the max value is always robbing it.
        dp[1] = nums[0]

        for i in range(2, l + 1):
            # DP array is 0-indexed and has an offset of 1 comparing with the nums array, so nums[i - 1] is the value
            # of the i-th house.
            dp[i] = max(dp[i - 2] + nums[i - 1], dp[i - 1])

        return dp[-1]
