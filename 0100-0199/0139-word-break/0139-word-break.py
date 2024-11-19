"""
[NEED_REVIEW]

A typical bottom-up DP problem: if s[:x] can be spelled using dict words, and s[x:y] is a word as well, the s[:y] can be spelled. In other
words, for each index i, we can check if there exists an index 0 < j < i, which is reachable by itself, and s[j:i] is a word.

The reachable status for all indice can be initialized as False in a DP array, and there should be an additional True off the start of the array
to represent the starting point.

N = len(s)
M = len(wordDict)

Time complexity:
- O(N^2), for the nested loops.

Space complexity:
- O(N + M), for word set and DP array.
"""
class Solution(object):
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: bool
        """
        words = set(wordDict)
        n = len(s)

        # Init DP, with first slot as reachable
        dp = [True] + [False] * n

        for i in range(1, n + 1):
            for j in range(i):
                # If j was reachable and [j:i] is a word, then o is reachable.
                if dp[j] and s[j:i] in words:
                    dp[i] = True
                    # No need to check further for i.
                    break

        return dp[n]
