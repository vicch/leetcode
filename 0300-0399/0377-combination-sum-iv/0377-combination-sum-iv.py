"""
Consider this as jumping stairs, each jump can be any value in the nums array, and the goal is to count the different
ways to jump the target number of stairs.

Similar to #139 Work Break, DP array contains the total number of ways to reach each value. On the basis of the ways to
reach value i (i.e. dp[i]), each value n in the nums array will increase the ways to reach value i+n by the value of
dp[i].

From bottom up, dp[0] = 1, and when iteration reaches the target value, dp[target] contains the total number of ways to
reach target value.
"""
class Solution(object):
    def combinationSum4(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        dp = [0] * (target + 1)
        dp[0] = 1

        nums.sort()

        for i in range(target + 1):
            for n in nums:
                if i + n > target:
                    break
                dp[i + n] += dp[i]

        return dp[-1]
