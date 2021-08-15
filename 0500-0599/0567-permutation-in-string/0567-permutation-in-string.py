"""
Basically a sliding window problem: slide a window of len(s1) on s2, and check if the sub-string under current window
is a permutation.

The checking of permutation is done via counting the letters of s1, and compare with the counts of letters in current
window of s2. It can be simplified by using a hash map to keep count of each letter and update them as the sliding
window moves (the removed letter's count is decremented if it's in s1, the added letter's count is incremented, if it's
in s1).

And use a separate counter to store the number of letters whose count remain to be matched. When this counter becomes 0,
it means all letters count in s1 is matching with current window, and a permutation is found.
"""

class Solution(object):
    def checkInclusion(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        l1, l2 = len(s1), len(s2)

        if l1 > l2:
            return False

        # Counts of letters, positive values means the count of that letter is larger in s1 than in current window on
        # s2, negative means the opposite, 0 means counts matching. When all counts become 0, a permutatoin is found.
        letters = {}
        # Number of values that are not 0 at any time in the letters map. When it becomes 0, a permutatoin is found.
        remain = 0

        # Init letters and remaining count by s1
        for l in s1:
            if l not in letters:
                letters[l] = 0
                # A new letter is found
                remain += 1
            letters[l] += 1

        for i in range(l2):
            # Any time a permutation is found, return true
            if remain == 0:
                return True

            # Maintain count of the letter before current window, i.e. the window just moved off of this letter
            if i >= l1 and s2[i - l1] in letters:
                letters[s2[i - l1]] += 1
                # If the removed letter's count is 1, meaning it was previously 0, and by removing it, there is one
                # more letter remaining to be matched
                remain += 1 if letters[s2[i - l1]] == 1 else 0

            # Maintain count of the letter at the end of current window, i.e. the window just moved on to this letter
            # to
            if s2[i] in letters:
                letters[s2[i]] -= 1
                # If this letter's count is 0, meaning this letter just matched
                remain -= 1 if letters[s2[i]] == 0 else 0

        # Last chance to match, check the remaining count after iterating the last letter of s2
        return remain == 0
