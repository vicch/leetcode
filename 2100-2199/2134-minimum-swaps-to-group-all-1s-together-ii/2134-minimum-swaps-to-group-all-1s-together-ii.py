"""
[NEED_REVIEW]

The goal is to concentrate all ones into a consecutive sub-array. Consider this result sub-array as a window that could
start at any index, the task is basically to find the window that already has the max possible ones in it, thus the min
swaps is needed to fill in the missing spots in the window.

So it's a sliding window problem, that we maintain a global optimal of number of ones while sliding it.

Every time it slides, we only care about the numbers on the two borders when updating the number of ones in the new
window.

Another sub-problem is the array being circular. One approach to simplify the logic is to concatenate a copy of the
array (or just the start of it, depending on the window length) to the original one. Or we can just reset the right
index when it reaches the end.
"""
class Solution(object):
    def minSwaps(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        l = len(nums)
        # The window length is determined by the length of the eventual sub-array, and thus the number of ones
        ones = sum(nums)

        # Return early on edge cases
        if ones == 0 or ones == l:
            return 0

        window_ones = sum(nums[:ones])
        window_ones_max = window_ones
        # Init window right border
        j = ones - 1

        for i in range(l):
            # Stretch window right border
            j += 1
            if j == l:
                j = 0

            # Decr and incr number of ones in the window
            window_ones -= nums[i]
            window_ones += nums[j]
            window_ones_max = max(window_ones_max, window_ones)

        return ones - window_ones_max
