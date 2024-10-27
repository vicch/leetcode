"""
[NEED_REVIEW]

As this involves open and closing parentheses, it's natural to consider using a stack to store the sub-strings to be
concatenated. The question is when to push and pop, and how to carry the result along the process.

There are 3 cases when traversing the string:
- When the char isn't a parenthese, it's natural to appending it to a running string as it's essentially always grouped
  with its previous letter, whether it should be reversed or not.
- When the char is a closing parenthese, the current running sub-string needs to be reversed. And it should be appended
  to the previous sub-string, which can be popped from the stack.
- Finally when it's an opening parenthese, it means a new sub-string starts, and the current running string should be
  pushed to stack.
"""
class Solution(object):
    def reverseParentheses(self, s):
        """
        :type s: str
        :rtype: str
        """
        stack = []
        running = ''

        for c in s:
            if c == '(':
                stack.append(running)
                running = ''
            elif c == ')':
                running = stack.pop() + running[::-1]
            else:
                running += c

        return running
