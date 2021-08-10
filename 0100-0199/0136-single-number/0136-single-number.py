"""
Thinking it in binary sense: for all numbers that show up twice, all 0s and 1s in their binay representations show up
in pairs. No matter what order these bits show up, XOR the same bit of 1 twice always resets it to 0. Except for the
number that shows up only once, whose bits will remain and not reset to 0.

Just reduce the list with XOR operation, and the remaining value is the number that shows up only once.
"""

class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return reduce(lambda a, b: a ^ b, nums)
