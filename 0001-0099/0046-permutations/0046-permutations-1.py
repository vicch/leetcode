"""
Typical backtracking problem: from a list of possible next values, pick each of them to extend a running prefix, then
send the extended prefix and remaining numbers to next level. When it reaches the bottom, i.e. no more values to select
from, a permutation is generated.

Collect these permutations in a shared list.
"""

class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        permutations = []

        def recursive(prefix, nums):
            if not nums:
                # Reached the bottom, add new permutation
                permutations.append(prefix)
                return

            for i in range(len(nums)):
                # Extend current prefix with next number, call next level with extended prefix and remaining numbers
                recursive(prefix + [nums[i]], nums[:i] + nums[i+1:])

        recursive([], nums)

        return permutations
