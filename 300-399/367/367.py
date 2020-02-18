"""
Problem:
Given a positive integer, write a function to determine if it is a perfect
square. Do not use any built-in library function such as sqrt().

Solution:
If   2^n < x < 2^(n+1)
Then 2^(n/2) < x^(1/2) < 2^((n+1)/2)
So by right shifting a number half the number of its binary digits, we can
get the lower boundary of its possible square root.
- Get the number of binary digits n.
- Right shift the number ceil(n/2) bits to get lower boundary of square root.
- Increment the value and calculate its square.
- Once the sqaure is greater than the integer, it's not a perfect square.
"""

class Solution(object):
    def isPerfectSquare(self, num):
        """
        :type num: int
        :rtype: bool
        """
        n = self.getBinaryDigits(num)
        base = num >> ((n + 1) >> 1)
        while base * base < num:
            base += 1
        return base * base == num

    def getBinaryDigits(self, num):
        """
        :type num: int
        :rtype: int
        """
        n = 0
        while num != 0:
            n += 1
            num >>= 1
        return n