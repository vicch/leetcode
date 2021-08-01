"""
Consider the DP array to contain the max amount that can be robbed on after each house n. There are 2 values to be
compared:

- If robbing this house, the total value will be dp[n - 2] + nums[n].
- If not robbing this house, the total value will be dp[n - 1], i.e. the max amount after the last house (whether it
was robbed or not).

So dp[n] = max(dp[n - 2] + nums[n], dp[n - 1]). Build the DP array from bottom up till the last house.
"""
class Solution(object):
    def rob(self, nums):
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
