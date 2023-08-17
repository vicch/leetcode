"""
This is actually a two pointer problem, where the answer can be found by moving the pointers from 2 ends towards the
middle. Which pointer to move depends on the current sum > or < the target.
"""
class Solution(object):
    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        l, r = 0, len(numbers) - 1
        while l < r:
            s = numbers[l] + numbers[r]
            if s == target:
                return [l+1, r+1]
            elif s > target:
                r -= 1
            else:
                l += 1
        return [-1, -1]
