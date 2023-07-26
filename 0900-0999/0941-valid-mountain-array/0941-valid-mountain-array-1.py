"""
Essentially comparing adjacent number pairs for up-slope and down-slope phases. The key is to detect the summit and
switch the rule. Also it involves edge case consideration:
- Adjacent numbers can't be equal.
- There may be monotonic arrays, and summit cannot be first or last element.
"""
class Solution(object):
    def validMountainArray(self, arr):
        """
        :type arr: List[int]
        :rtype: bool
        """
        if len(arr) < 3:
            return False

        # Exclude monotonic edge cases
        if arr[0] > arr[1] or arr[-2] < arr[-1]:
            return False

        reachedTop = False

        for i in range(len(arr) - 1):
            # Exclude equal pairs
            if arr[i] == arr[i+1]:
                return False

            if not reachedTop:
                # Should be increasing before reaching the top
                if arr[i] < arr[i+1]:
                    continue
                else:
                    # Reaching the top for once
                    reachedTop = True
            else:
                # Should be decreasing after the top
                if arr[i] < arr[i+1]:
                    return False
        
        return True
