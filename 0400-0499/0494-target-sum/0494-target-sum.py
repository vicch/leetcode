"""
A typical DP problem. Each number can be either added or substracted, which alters the target value accordingly for the next step, basically:

ways[i][target] = ways[i+1][target-nums[i]] + ways[i+1][target+nums[i]]

The ways can be cached in a DP memo to avoid duplicate check.

Time complexity:
- O(N * M), N = numbers count, M = sum(nums), because the target range for each number is (-M, M), and each target value is processed once per
  number.

Space complexity:
- O(N * M), same as above.
"""
class Solution(object):
    def findTargetSumWays(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        l = len(nums)
        # 2D DP cache, memo[i][n] = number of ways to get to target number n starting from index i.
        memo = [{} for _ in range(l)]

        def dfs(i, subTarget):
            # Bottom of DFS, it's a solution if target is 0 after the last index.
            if i == l:
                return 1 if subTarget == 0 else 0

            if subTarget in memo[i]:
                return memo[i][subTarget]
            
            # DFS next index, by either adding or substracting the current number.
            ways = dfs(i + 1, subTarget - nums[i]) + dfs(i + 1, subTarget + nums[i])
            memo[i][subTarget] = ways

            return ways
        
        return dfs(0, target)
