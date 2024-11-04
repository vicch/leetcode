"""
[NEED_REVIEW]

With the asterisk being to serve as either an open or a close parenthesis, the validation can be 2 steps:

1. Validate that when traversing the string in forward, there is always more or equal opening parenthesis at any location, assuming all
   asterisks are opening parenthesis.
2. Similarly, when reversing the string, there is always more or equal closing parenthesis, assuming all asterisks are closing parenthesis.

(Strictly this doesn't seem to convincingly prove that the string is valid, but it works, and no exception can be given.)

Time complexity:
- O(N), for traversing the string twice.

Space complexity:
- O(1), for the counters.
"""
class Solution(object):
    def checkValidString(self, s):
        """
        :type s: str
        :rtype: bool
        """
        open = 0
        for c in s:
            if c == ')':
                open -= 1
            else:
                open += 1
            if open < 0:
                return False
        
        close = 0
        for c in s[::-1]:
            if c == '(':
                close -= 1
            else:
                close += 1
            if close < 0:
                return False
        
        return True
