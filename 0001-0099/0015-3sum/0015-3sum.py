"""
The process:

1. Fix one number first, e.g. nums[i], and find the other 2 numbers adding up to a target value, i.e. 0 - nums[i]. To
speed up this process, the numbers should be sorted first.
2. Use 2 pointers to start looking for the solutions from head and tail.
3. If the sum of head and tail values is larger than target, tail should be moved to a smaller value.
4. If it's smaller than target, head should be moved to a larger value.
5. Once a matching sum is found, add all 3 numbers to the solutions list.

Note that to eliminate duplicate solutions:

- Duplicate values for the first number should be skipped, because any solution starting with the dup value must have
been added in previous outer cycle.
- After finding each solution, either head or tail pointer needs to move to a different value before next inner cycle.
"""

class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        triplets = []
        nums.sort()

        for i in range(len(nums)-2):
            # If first number is positive, remaining numbers can only be larger, which won't be possible to add up to 0
            if nums[i] > 0:
                break
            # Skip duplicate numbers as the solutions starting with them must have been covered
            if i > 0 and nums[i] == nums[i-1]:
                continue

            target = 0 - nums[i]
            # Range of the remaining 2 numbers
            l, r = i + 1, len(nums) - 1

            while l < r:
                # Shrink right border if too large
                if nums[l] + nums[r] > target:
                    r -= 1
                # Shrink left border if too smaller
                elif nums[l] + nums[r] < target:
                    l += 1
                else:
                    triplets.append([nums[i], nums[l], nums[r]])
                    # Move left border to find next non-dup number
                    l += 1
                    while l < r and nums[l] == nums[l-1]:
                        l += 1

        return triplets