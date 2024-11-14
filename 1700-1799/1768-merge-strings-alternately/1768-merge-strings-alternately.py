"""
Just use one pointer to traverse both strings, and append the chars at each index if it's within the string boundary.

Time complexity:
- O(N + M), for traversing the strings.

Space complexity:
- O(N + M), for the merged string.
"""
class Solution(object):
    def mergeAlternately(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: str
        """
        l1, l2 = len(word1), len(word2)
        merged = []

        for i in range(max(l1, l2)):
            if i < l1:
                merged.append(word1[i])
            if i < l2:
                merged.append(word2[i])
        
        return "".join(merged)
