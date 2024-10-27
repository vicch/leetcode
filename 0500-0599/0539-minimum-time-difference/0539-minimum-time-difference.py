"""
It is natrual to think of sorting the time points and maintain a global optimal of min diff while traversing the values.
And there is actually no better approach than that.

The trick is:
- Time point representation and conversion from string, which essentially converting from base 60 to 10.
- Time points are a cycle, and the diff between last and first values need to be checked, which can be simplified as
  appending the first value as if it's on next day (+24 hours).
"""
class Solution(object):
    def findMinDifference(self, timePoints):
        """
        :type timePoints: List[str]
        :rtype: int
        """
        minutes = [self._convert(str) for str in timePoints]
        minutes.sort()

        # Handling time cycle by appending first time point to next day.
        minutes.append(minutes[0] + 1440)

        minDiff = float('inf')
        for i in range(len(minutes) - 1):
            minDiff = min(minDiff, minutes[i+1] - minutes[i])

        return minDiff

    def _convert(self, str):
        base = ord('0')
        # Convert each digit directly, which is simpler than getting hours value first then convert to minutes.
        return (ord(str[0]) - base) * 600 + (ord(str[1]) - base) * 60 + (ord(str[3]) - base) * 10 + (ord(str[4]) - base)
