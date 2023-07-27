"""
The implicit requirement is to not re-order the elements, instead directly partition the original array. So the method
is to first get the target sum of each partition, then accumulate the numbers from one end towards that target, and
after hitting the target twice, check if there is remaining number.

The tricky part is to handle the edge cases, such as [0, 0, 0, 0]. And there is no need to check the sum of remaining
numbers because they must add up to the target value as well.
"""
class Solution(object):
    def canThreePartsEqualSum(self, arr):
        """
        :type arr: List[int]
        :rtype: bool
        """
        # Return early if the sum of all elements cannot be divided by 3 in the first place
        if len(arr) < 3 or sum(arr) % 3 != 0:
            return False
        
        target = sum(arr) / 3

        i, current, partition = 0, 0, 0

        # Iterate and end when 2 partitions are found
        while i < len(arr) - 1 and partition < 2:
            current += arr[i]
            i += 1

            # Finding one parition
            if current == target:
                partition += 1
                current = 0

        # If there is number remaining after getting 2 partitions, it succeeds.
        # There is no need to check the sum of remaining numbers anymore.
        return i < len(arr) and partition == 2
