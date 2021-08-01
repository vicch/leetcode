"""
Similar to #139 Word Break, for the DP array, each element stores the different ways to parse the sub-substring up to
this index (DP[1] being the ways to parse the 1st char in the string).

For each DP[i]:

- If its next char can be decoded (i.e. between "1" and "9"), then the ways to decode up to next char
(i.e. DP[i+1]) is incremented by DP[i].
- If its next 2 chars can be decoded (i.e. between "10" and "26") then dp[i+2] is incremented by dp[i].

Iterate all locations from bottom up, then last value in DP array is the different ways to parse to the last char.
"""
class Solution(object):
    def numDecodings(self, s):
        """
        :type s: str
        :rtype: int
        """
        l = len(s)
        # DP array is 0-index with index i corresponding to s[i], and index 0 indicate the location before 1st char.
        # Init the ways to reach the location before 1st char to be 1.
        dp = [1] + [0] * l

        for i in range(0, l):
            # If next char is 0, there is no way a code can be mapped (all codes don't start with 0).
            if s[i] == "0":
                continue
            # If next char is between 1 and 9, it can be decoded.
            dp[i+1] += dp[i]
            # If the remaining char is only 1, skip trying to decode the next 2 chars.
            if i >= l-1:
                continue
            # If next 2 chars are between 10 and 26, they can be decoded.
            if s[i] == "1" or (s[i] == "2" and int(s[i+1]) < 7):
                dp[i+2] += dp[i]

        return dp[-1]
