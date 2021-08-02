"""
For each char in the string, there is a longest sub-string ending on this char that contains no repeating letters. This
sub-string starts from the next char of this letter's last appearance.

The current global longest sub-string's length can be updated if the current sub-string is longer. At the end of the
string, this global value covers the whole string and is the needed result.

To maintain each letter's last appearance, a hash map can be used, and updated while iterating the chars.
"""
class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        lastPos = {}
        # Starting index of current sub-string without repeating letters
        # Length of global longest sub-string without repeating letters so far
        winStart, maxLen = 0, 0

        for i in range(len(s)):
            # If this letter's last appearance is within the current sub-string, the sub-string up to this letter is
            # updated to start from the next letter of its last appearance, to remain not having repeating letters.
            if s[i] in lastPos and winStart <= lastPos[s[i]]:
                winStart = lastPos[s[i]] + 1
            # If not, then current sub-string is extended to this letter, update global max length if needed.
            else:
                maxLen = max(maxLen, i - winStart + 1)

            # Memo the last appearance of this letter.
            lastPos[s[i]] = i

        return maxLen
