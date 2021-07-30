"""
For an array with N numbers, it's missing a number between 0 and N. The sum of all numbers between 0 and N can be
calculated easily. Then by comparing this sum with the actual sum of numbers in the array, the missig one can be
identified.
"""
class Solution(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        total = (1 + n) * n / 2
        return total - sum(nums)
