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
        return ''.join([char * times for char, times in collections.Counter(str).most_common()])