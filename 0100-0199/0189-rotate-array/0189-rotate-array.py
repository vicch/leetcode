"""
Rotating the array by k steps, e.g. [1,2,3,4,5,6,7] by 3 step, is actually:

1. Reverse the whole array:        [7,6,5,4,3,2,1]
2. Reverse first k elements:       [5,6,7,4,3,2,1]
3. Reverse the remaining elements: [5,6,7,1,2,3,4]
"""

class Solution(object):
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        # Reverse array between index i and j
        def reverse(i, j):
            while i < j:
                nums[i], nums[j] = nums[j], nums[i]
                i += 1
                j -= 1

        l = len(nums)
        k = k % l
        reverse(0, l-1)
        reverse(0, k-1)
        reverse(k, l-1)

        return nums
