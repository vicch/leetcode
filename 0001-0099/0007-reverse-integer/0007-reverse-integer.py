"""
Simply pop last digit of original number and push into new number via modulo operation, and shift right and left the
two numbers, till the original one reaches 0. Also watches for 32-bit integer boundary, and return early if the
revered number exceeds it.

To handle negative integer, get its sign in the beginning and apply it in the end.

Time: O(logn), because the operation is per digit, or O(1) if considering the 32-bit range as constant
Space: O(1)
"""
class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        sign = 1
        if x < 0:
            x = -x
            sign = -1

        maxInt = 2 ** 31 - 1

        y = 0
        while x > 0:
            y = y * 10 + x % 10
            x /= 10

            if y > maxInt:
                return 0

        return y * sign
