"""
Similar to #647 Palindromic Substrings, try to get the longest palindrome with each index as center, and maintain the
global longest palindrome.

We need to return the sub-string instead of length, so index of the longest palindrome needs to be maintained.
"""
class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        length = len(s)

        # Return the longest palindrome with the given left and right index as center
        def getLongest(l, r):
            # Extend palindrome till index are out of bound, or letters don't match
            while l >= 0 and r < length and s[l] == s[r]:
                l -= 1
                r += 1
            # The loop extends the index to the point that it's no longer palindrome, revert them by 1 to get the last
            # palindrome
            return [l+1, r-1]

        # Init longest palindrome left and right index
        m = [0, 0]

        # Get "aba" type of palindromes
        for i in range(length):
            p = getLongest(i, i)
            # If new palindrome is longer, update global longest
            if p[1] - p[0] > m[1] - m[0]:
                m = p

        # Get "abba" type of palindromes
        for i in range(length-1):
            p = getLongest(i, i+1)
            if p[1] - p[0] > m[1] - m[0]:
                m = p

        # Return sub-string via the left and right index
        return s[m[0]:m[1]+1]
