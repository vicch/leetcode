"""
Simplified version: assuming the array is mountain array, try to find its summit while traversing, and check if the
array can be fully traversed by assuming it's mountain array, and if the summit is in the middle.
"""
class Solution(object):
    def validMountainArray(self, arr):
        """
        :type arr: List[int]
        :rtype: bool
        """
        if len(arr) < 3:
            return False

        i = 0

        # Traverse while it's increasing (i.e. not reaching the summit) and not reaching the end
        while i < len(arr) - 1 and arr[i] < arr[i+1]:
            i += 1
        
        # If traversal stopped, it has reached the summit (or reached the end, which can be handled in the same way)
        summit = i

        # Traverse while it's decreasing and not reaching the end
        while i < len(arr) - 1 and arr[i] > arr[i+1]:
            i += 1

        # If summit is in the middle, and traversal has reached the end, it's mountain array
        return 0 < summit < len(arr) - 1 and i == len(arr) - 1
