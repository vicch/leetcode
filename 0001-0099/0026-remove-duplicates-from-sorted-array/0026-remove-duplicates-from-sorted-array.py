"""
Use 2 pointers:

- Slow pointer at the tail of the list without dups (sub-list at the front of the whole list).
- Fast pointer iterates the list.

The case when slow pointer needs to move, is when the 2 pointers point to different values, i.e. fast pointer meets a
new value to be kept. Overwrite this value to the tail of the sub-list, then move slow pointer.
"""

class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        l, r = 0, 0

        while r < len(nums):
            # If r points to a different number than l, this number needs to be kept
            if nums[l] != nums[r]:
                # Overwrite this number to next cell of the kept list
                l += 1
                nums[l] = nums[r]
            # Fast pointer moves forward no matter what
            r += 1

        return l + 1
