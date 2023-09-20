"""
A DP problem, the key is to find the DP function: dp(string) = min(dp(subString1), ...) + 1, where the subString is the string
minus the letters that can be provided by each sticker. E.g.

- stickers = ["a", "b", "c"], target = "abcd"
- dp("abcd") = min(dp("bcd"), dp("acd"), dp("abd")) + 1, where "bcd" = string "abcd" - sticker "a"

So the high level process is to populate the DP array recursively from top to bottom (dp("") == 0), return dp[target]
at the end.

Note that the DP mem key needs to be able to cover all permutations of a certain string, e.g. dp("abc") should cover
both "abc" and "cbd". One option is to sort the letters of the string, so all permutations will hit the same entry.
"""
class Solution(object):
    def minStickers(self, stickers, target):
        """
        :type stickers: List[str]
        :type target: str
        :rtype: int
        """
        stickerLetters = [self._countLetters(s) for s in stickers]
        # DP mem, init with bottom value.
        mem = {"": 0}

        """
        DP helper that computes min sticker for given string, and populates DP mem.
        """
        def dpHelper(string):
            # Return if already computed.
            if string in mem:
                return

            stringLetters = self._countLetters(string)

            # Store min sticker candidates.
            candidates = []

            for sticker in stickerLetters:
                # An optimization to narrow the DP search space: if the remaining string can be covered by multiple
                # stickers (i.e. there are multiple choices for next DP step), there must be at least one sticker that
                # contains the first char (arbitrary decision, picking any char should work), so narrow down to those
                # stickers at this level.
                if sticker[string[-1]] == 0:
                    continue

                # Letters in the remaining string if letters in current sticker are used.
                subStringLetters = []
                for k in stringLetters:
                    # The remaining string contains letters that cannot be fully covered by the sticker.
                    if stringLetters[k] > sticker[k]:
                        subStringLetters.extend([k] * (stringLetters[k] - sticker[k]))
                # Sorting the letters as a unified key for the DP mem.
                subStringLetters.sort()
                subString = "".join(subStringLetters)

                # Compute and populate DP for next level.
                dpHelper(subString)

                # If there is a solution for the remaining string, add as candidate.
                if mem[subString] != -1:
                    candidates.append(mem[subString])
            
            # If there no candidate at all, the current string cannot be made by the stickers. Otherwise the DP value
            # is the min of all sub-string DPs plus 1.
            mem[string] = min(candidates) + 1 if candidates else -1
        
        dpHelper(target)
        return mem[target]
    
    """
    Count number of each letter in a string. As there are only 26 letters, another option is to use a list with 26
    elements to represent the letters count of a string.
    """
    def _countLetters(self, string):
        letters = collections.defaultdict(int)
        for c in string:
            letters[c] += 1
        return letters
