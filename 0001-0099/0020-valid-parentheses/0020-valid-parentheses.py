"""
Use a stack:

- When opening parenthese is met, push to stack.
- When closing parenthese is met, pop the stack and check if they match.

At any time if the parentheses don't match, or stack is empty on meeting a closing parenthese before the end of the
string, it's invalid.
"""
class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        pairs = {"(": ")", "[": "]", "{": "}"}
        stack = []

        for c in s:
            # Opening parenthese
            if c in pairs:
                stack.append(c)
            elif len(stack) == 0 or pairs[stack.pop()] != c:
                return False

        return len(stack) == 0
