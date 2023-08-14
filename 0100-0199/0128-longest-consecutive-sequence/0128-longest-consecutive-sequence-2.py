"""
The key is a performant way to check for a certain number's existence in the list, which can be achieved with hash map.
By knowing if a number exists, we can try to extend the incrementing sequence from each number in the list:
- If x exists, check if x + 1 exists.
- Stop when the next value doesn't exist, then the local longest sequence is found.

It can be optimized by ignoring x if x - 1 exists, because each number will be iterated once, so the starting number of
each local sequence will be checked at some point, and no sequence will be missed.
"""
class Solution(object):
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums = set(nums)
        l = 0
        for n in nums:
            if n - 1 in nums:
                continue
            m = n + 1
            while m in nums:
                m += 1
            l = max(l, m - n)

        return l
