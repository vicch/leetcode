"""
The key is to find the step transition for s[:n] to s[:n+1], if we have the min flips to turn s[:n] into monotone
increasing, then we can extend it to s[:n+1] depending on the char s[n+1]:

If it's 1, then there is no flip needed, i.e. f(s[:n+1]) == f(s[:n])

If it's 0, then there are 2 options:
- Either flip it to 1 and append to already monotone increasing s[:n], i.e. f(s[:n+1]) = f(s[:n]) + 1
- Or don't flip it, but flip all the 1s before it, i.e. f(s[:n+1]) = count(num of 1 in s[:n])

f(s[:n+1]) is the smaller value of the 2 options.

The value of flips is also monotone increasing as the string is extended, so we can keep a single running value, instead
of a DP array.
"""
class Solution(object):
    def minFlipsMonoIncr(self, s):
        """
        :type s: str
        :rtype: int
        """
        flips, ones = 0, 0

        for c in s:
            if c == '1':
                ones += 1
            else:
                flips = min(ones, flips + 1)

        return flips
