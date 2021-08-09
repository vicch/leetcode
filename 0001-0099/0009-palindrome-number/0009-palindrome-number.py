"""
Same as #125 Valid Palindrome, just convert number to string and check chars from head and tail.
"""
class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        # According to defition, all negative numbers are not palindrome
        if x <= 0:
            # 0 is palindrome though
            return x == 0

        s = str(x)
        for i in range(len(s) // 2):
            if s[i] != s[~i]:
                return False

        return True
