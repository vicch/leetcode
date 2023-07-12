"""
Improve version 1: for any number that has already been locked, we already found the closest by including this number,
so it can be excluded altogether from subsequent attempts. Which means for the "2Sum Closest" sub-problem, we don't
need to use all remaining numbers for the list, just numbers that haven't been locked yet. Basically instead of
`nums[:i] + nums[i+1:]`, we only need `nums[i+1]`.

The extra method can also be skipped, and just perform "2Sum" in place on the right sub-list.
"""
class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        # If there is at most 3 numbers, the closest is their sum
        if len(nums) < 4:
            return sum(nums)

        nums.sort()

        # Initial optimal with infinity
        closest = float('inf')

        for i in range(len(nums) - 2):
            locked = nums[i]

            # 2 pointers at start and end of the sub-list nums[i+1:]
            l, r = i + 1, len(nums) - 1

            while l < r:
                current = locked + nums[l] + nums[r]

                # No better result can be found
                if current == target:
                    return target

                if abs(current - target) < abs(closest - target):
                    closest = current

                if current < target:
                    l += 1
                else:
                    r -= 1

        return closest
