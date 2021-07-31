"""
Consider DP:

- If sub-string s[0:n] can be spelled using dict words, and the following m chars matches one of the words in the dict,
then sub-string s[0:n+m] can be spelled using dict words.
- In contrast, if sub-string s[0:n] cannot be spelled, then even if the following chars match any of the words, there is
no way the whole string can be spelled using dict words, and this branch can be cut.

Iterate all locations of the string while maintaining the DP array. The last value of DP array indicates whether the
whole string can be spelled.
"""
class Solution(object):
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: bool
        """
        sl = len(s)
        dp = [True] + [False] * sl

        for i in range(sl + 1):
            # If there is no way to reach this char using dict words, it cannot be a starting point
            if not dp[i]:
                continue

            for word in wordDict:
                l = len(word)

                # 2 situations when this word is not needed to check:
                # - If word is longer than the remaining part of string.
                # - If there is already a way to reach the same location as appending this word.
                if i+l > sl or dp[i+l]:
                    continue

                # If the next N letters match the word, the spell-able sub-string can be extended by this word.
                if s[i:i+l] == word:
                    dp[i+l] = True

        return dp[-1]
