"""
There should be a local optimal result at any moment, which starts with  the first number of the array. The local
optimal result is the longest list of sorted numbers from the input so far.

To merge the next number N into the optimal result, it needs to be placed at the location where the result remain a
sorted list. It overwrites the first number that is > N.

Continue this step, the final result will be the longest incrementing sub-array.
"""
import bisect

class Solution(object):
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        sortedNums = []

        def insert(num):
            # Find index of the first number that is >= num, using binary search library
            i = bisect.bisect_left(sortedNums, num)
            # If the index is past the end, it means all existing numbers are < num, append to the end in this case
            if i == len(sortedNums):
                sortedNums.append(num)
            # Overwrite the number
            else:
                sortedNums[i] = num

        for num in nums:
            insert(num)

        return len(sortedNums)
