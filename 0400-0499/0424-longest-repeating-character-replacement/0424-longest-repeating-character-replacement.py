"""
Consider any sub-string in the string, to turn all chars in it into the same letter, the most likely way (in terms of
the least number of letter changes needed) is to turn all letters into the most common letter, i.e. the letter whose
count within the sub-string is the largest.

The sub-string can be considered as a sliding window. It can be exist when the number of letter changes needed (i.e.
window size - number of the most common letter in the window) is not bigger than K.

Once a locally longest window is found, keep the window size and slide to the next char, and check if the window is
possible to keep up.

- If yes, the window size is extended by 1.
- If not, keep the current window size, maintain the letter counts in the window and continue sliding.

The window size at the end of the string is the global longest window that could exist by changing no more than K
letters in any sub-string (with same size of the window).
"""
import collections

class Solution(object):
    def characterReplacement(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        # Counters of each letter in the window, use collections.Counter because it doesn't need init
        counts = collections.Counter()
        window, majority = 0, 0

        for i in range(len(s)):
            counts[s[i]] += 1
            # Refresh the count of the most common letter in current window
            majority = max(majority, counts[s[i]])
            # Check if it's possible (the number of letters to be changed is not bigger than K) to change all other
            # letters in the window to the most common letter
            if window - majority >= k:
                # If not, window needs to shrink (window was extended by 1 at the start of the loop) to its previous
                # size, and the letter at the start is now out of the window, so decrement its count (in the window)
                counts[s[i - window]] -= 1
            else:
                # If yes, window is extended by 1
                window += 1

        return window
