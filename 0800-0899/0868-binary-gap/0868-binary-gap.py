"""
The binary representation is essentially a sequence of 0s and 1s, and the problem is just to count local distance and
the global max distance between the 1s.
"""
class Solution(object):
    def binaryGap(self, n):
        """
        :type n: int
        :rtype: int
        """
        max_gap = 0
        index, last_one_index = -1, -1

        # Truncate and get the last digit of n, maintain the current index
        while n:
            digit, n = n % 2, n / 2
            index += 1

            # Skip 0s
            if digit == 0:
                continue

            # If there was a previous 1, get the current gap and maintain global max
            if last_one_index > -1:
                max_gap = max(max_gap, index - last_one_index)

            last_one_index = index

        return max_gap
