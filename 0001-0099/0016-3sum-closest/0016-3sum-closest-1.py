"""
Similar solution to the 3Sum problem: lock one number first, and simplify the problem to a "2Sum Closest". Find the
local optimal, update global optimal if it's better, then move on to lock the next number.

The "2Sum Closest" can be solved by moving 2 pointers from start and end of the sorted list, to move accordingly to
close in on the target value.
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

        # Initial optimal
        closest = nums[0] + nums[1] + nums[-1]

        for i in range(len(nums)):
            # Lock current number as selected
            locked = nums[i]

            # Find closest 2sum within the remaining numbers
            candidate = self.twoSumClosest(nums[:i] + nums[i+1:], target - locked)

            # The best possible result is found
            if candidate + locked == target:
                return target

            # Update optimal if better result is found
            if abs(candidate + locked - target) < abs(closest - target):
                closest = candidate + locked

        return closest

    def twoSumClosest(self, nums, target):
        i, j = 0, len(nums) - 1

        # Initial optimal
        closest = nums[i] + nums[j]

        while i < j:
            candidate = nums[i] + nums[j]

            # The best possible result is found
            if candidate == target:
                return candidate

            # Update optimal if better result is found
            if abs(candidate - target) < abs(closest - target):
                closest = candidate

            # Move pointer to get potentially better result
            if candidate < target:
                i += 1
            else:
                j -= 1

        return closest
