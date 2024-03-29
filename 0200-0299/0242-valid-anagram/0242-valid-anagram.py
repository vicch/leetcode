"""
Firstly anagrams need to be the same length.

Collect counts of each letter of the 1st string. Then for each letter in the 2nd string, if the letter wasn't in 1st
string, or if its count is larger (reduce the letter's count each time it's met, so when the count is < 0, its count is
larger in the 2nd string), it's not an anagram.
"""
class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        if len(s) != len(t):
            return False

        counts = collections.defaultdict(int)
        
        for c in s:
            counts[c] += 1
            
        for c in t:
            counts[c] -= 1
            if counts[c] < 0:
                return False

        return True
