"""
Simply interate the 2 strings with pointers while validating the abbr against the word. Whenever a numeric char is met
in the abbr, look for the end of the numeric part and parse out the length. The word pointer moves ahead by the length,
and the abbr pointer moves to the next non-numeric char. If both strings are fully iterated at the end, it's valid.

Time: O(n)
Space: O(1)
"""
class Solution(object):
    def validWordAbbreviation(self, word, abbr):
        """
        :type word: str
        :type abbr: str
        :rtype: bool
        """
        i = j = 0

        while i < len(word) and j < len(abbr):
            # Move on for matching chars.
            if word[i] == abbr[j]:
                i += 1
                j += 1
                continue
            
            # If not matching, and abbr char is non-numeric or 0, it's invalid.
            if not abbr[j].isnumeric() or abbr[j] == '0':
                return False

            # Look for the next non-numeric char.
            k = j
            while k < len(abbr) and abbr[k].isnumeric():
                k += 1

            # Parse out the abbr length, move the pointers accordingly.
            l = int(abbr[j:k])
            i += l
            j = k
        
        return i == len(word) and j == len(abbr)
