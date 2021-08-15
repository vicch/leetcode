"""
Compare rotated string is basically starting from each index of the original string, and compare if the letters starting
from this index (and resets to start when reaching end) is identical to the target string.

For each cycle, the comparison breaks early on any mismatching letter. If the comparison reaches the end of target
string, then it's a rotated string.
"""

class Solution(object):
    def rotateString(self, s, goal):
        """
        :type s: str
        :type goal: str
        :rtype: bool
        """
        if len(s) != len(goal):
            return False

        l = len(s)

        for i in range(l):
            for j in range(l):
                # If index is out of bound, reset to front of string
                index = i + j if i + j < l else i + j - l
                # Break on any mismatching letter
                if s[index] != goal[j]:
                    break
            # If it countinues to the last letter of goal without breaking, it's a rotate string
            if j == l - 1:
                return True

        return False
