"""
Essentially the "subset sum" problem: we need to find if there is a subset of the numbers that add up to a target value.

The DP transitioning between the steps, is that each number can be either included or excluded in the subset, and the
target value changes accordingly. The bottom is when a solution is found, or when the list is exhausted.

An obvious optimization is to use memorization to avoid re-attempting the same target value at the same index.

And by sorting the numbers in advance, cases can be pruned when the next number is already larger than the target.
"""
class Solution(object):
    def canPartition(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        def _dfs(i, target):
            if (i, target) in memo:
                return memo[(i, target)]

            # Return early if no solution is possible
            if i >= len(nums) or nums[i] > target:
                return False

            # Solution found
            if nums[i] == target:
                return True

            # Either include or exclude current number
            memo[(i, target)] = _dfs(i + 1, target - nums[i]) or _dfs(i + 1, target)
            return memo[(i, target)]

        total = sum(nums)
        if total % 2 == 1:
            return False

        nums.sort()
        half = total / 2

        # Memorize if target value can be achieved starting on index i.
        memo = {}
        
        return _dfs(0, half)
