"""
Typical backtracking. Use a stack to keep track of the path, instead of passing it along the recursive calls.
"""
class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        permutations = []
        stack = []
        
        def recursive(nums):
            if len(nums) == 0:
                permutations.append(list(stack))
                return

            for i in range(len(nums)):
                stack.append(nums[i])
                recursive(nums[:i] + nums[i+1:])
                stack.pop()
        
        recursive(nums)
        
        return permutations
