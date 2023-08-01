"""
Simply runningSum(n) = runningSum(n-1) + nums[n]
"""
class Solution(object):
    def runningSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        sums = [nums[0]]

        for num in nums[1:]:
            sums.append(sums[-1] + num)

        return sums
