"""
Firstly perform the normal palindrome validation with 2 pointers at head and tail moving towards the middle. The
difference, when a mismatch is found, perform another inner layer palindrome validation, by moving either the head or
the tail pointer by 1.

Time: O(n)
Space: O(1)
"""
class Solution(object):
    def validPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        l, r = 0, len(s) - 1

        while l < r:
            if s[l] != s[r]:
                return self._isValid(s[l+1:r+1]) or self._isValid(s[l:r])
            l += 1
            r -= 1

        return True

    def _isValid(self, s):
        l, r = 0, len(s) - 1

        while l < r:
            if s[l] != s[r]:
                return False
            l += 1
            r -= 1

        return True
