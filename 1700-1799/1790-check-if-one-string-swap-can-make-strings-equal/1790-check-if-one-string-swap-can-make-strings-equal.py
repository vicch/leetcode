"""
Most of the chars are equal if the strings are almost equal. We just need to find the indice where the chars aren't
equal, and check if there is exactly 1 pair of indice, and the chars are "cross-equal" at the indice.
"""
class Solution(object):
    def areAlmostEqual(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        # Not necessary as the strings are guaranteed to be of equal length.
        if len(s1) != len(s2):
            return False

        # Collect indice where chars aren't equal.
        diff = []
        for i in range(len(s1)):
            if s1[i] == s2[i]:
                continue
            diff.append(i)
            # Fail early if there are more than 2 diffs
            if len(diff) > 2:
                return False
        
        # Return true if there are exactly equal, or there is 1 pair of chars that can be swapped to make them equal.
        return len(diff) == 0 or (len(diff) == 2 and s1[diff[0]] == s2[diff[1]] and s1[diff[1]] == s2[diff[0]])
