"""
Problem:
Given a circular array, print the Next Greater Number for every element. The
Next Greater Number of a number is the first greater number to its
traversing-order next in the array. If it doesn't exist, output -1.

Example:
Input: [4, 1, 2, 5]
Output: [5, 2, 5, -1]

Solution:
Using stack to stores indices of the appropriate elements from nums array.
The top index refers to the Next Greater Element found so far. Traversing
the nums array from right to left. For each number, pop the stack until an
index is found that nums[stack[top]] > nums[i], then push i to stack.
"""

class Solution(object):
    def nextGreaterElements(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        stack, res = [], [-1] * len(nums)
        for i in range(len(nums)) * 2:
            while stack and (nums[stack[-1]] < nums[i]):
                res[stack.pop()] = nums[i]
            stack.append(i)
        return res