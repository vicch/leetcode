"""
Similar to #5 Longest Palindromic Substring, the radius of each palindrome is basically how many palindrome it contains
in total. E.g. "abcba" has a radius of 3 (considering single chars as radius 1) with "c" as center, and there are 3
palindromes in total: "c", "bcb", "abcba".

So by getting the longest palindrome starting from each index, and add them up, it will be total number of palindromes
in the string.

Note that there are 2 types of palindromes: "aba" and "abba".
"""
class Solution(object):
    def countSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        # Method to count the number of palindromes with given indexes as center
        def getCount(l, r):
            count = 0
            while l >= 0 and r < len(s) and s[l] == s[r]:
                count += 1
                l -= 1
                r += 1
            return count

        counts = 0
        for i in range(len(s)):
            # Accumulate the counts of palindromes of both types from each index
            counts += getCount(i, i) + getCount(i, i+1)

        return counts
