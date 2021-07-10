"""
Problem:
Sort a given string in decreasing order based on the frequency of characters.
Letters are case-sensitive.

Example:
Input: tree
Output: eetr

Solution:
- Array A contains characters to numbers of occurrences.
- Array B contains distinct characters
Sort characters in B by looking up its number of occurrence in A, then iterate
B to make a new string by repeating each character A[c] times.
"""

class Solution(object):
    def frequencySort(self, s):
        """
        :type s: str
        :rtype: str
        """
        times = {}
        for l in s:
            if not times.get(l):
                times[l] = 0
            times[l] += 1

        letters = sorted(list(set(s)), key=lambda i: times[i], reverse=True)

        new = ''
        for l in letters:
            new += l * times.get(l)

        return new