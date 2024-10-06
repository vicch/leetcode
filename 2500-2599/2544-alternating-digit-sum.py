"""
There are only 2 cases:
- If N has odd number of digits, result = digit_1 - digit_2 + ... + digit_n
- If N has even number of digits, result = digit_1 - digit_2 + ... - digit_n

When iterating the digits from the right end, we assume the last digit gets positive sign in the result, then alternate
the sign while iterating the digits till the left end.

At the end we check the total number of digits and decide if the result should be negated, i.e. all signs get flipped.
"""
class Solution(object):
    def alternateDigitSum(self, n):
        """
        :type n: int
        :rtype: int
        """
        sum = 0
        digit_sign = 1
        index = 0

        while n > 0:
            digit = n % 10

            sum += digit * digit_sign
            digit_sign *= -1

            n = n // 10
            index += 1

        if index % 2 == 0:
            sum *= -1

        return sum
