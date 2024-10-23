"""
Build the new string in 2 steps:
1. The interwoven part takes one char from each string per loop. It's determined by the shorter string of the two.
2. Append the remaining part of the longer string.

The code can be simplified with some tricks, e.g. we don't need conditional logic for part 2, just attempt to append
both sub-strings starting from the ending index of part 1, the shorter one will return empty.
"""
class Solution(object):
    def mergeAlternately(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: str
        """
        l1, l2 = len(word1), len(word2)
        lmin = min(l1, l2)

        merged = ''
        for i in range(lmin):
            merged += word1[i]
            merged += word2[i]

        # Append remaining part of both strings, the shorter one will be empty.
        merged += word1[lmin:]
        merged += word2[lmin:]

        return merged
