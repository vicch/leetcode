"""
Basically "min remove" is just removing "(" and ")" that are not matching, i.e.
- "(" that aren't closed at the end.
- ")" with no matching opening ones.

The matching of parentheses can naturally be achived with stack with the locations of "(", and every time the stack is
empty when a ")" is met, it needs to be removed. At the end, remaining locations of "(" also need to be removed.

A trick is to set the char to be empty, instead of memorizing the indice of chars to remove.

Time: O(n) for the iterations
Space: O(n) for the stack and string building
"""
class Solution(object):
    def minRemoveToMakeValid(self, s):
        """
        :type s: str
        :rtype: str
        """
        stack = []
        remove = set()

        for i, c in enumerate(s):
            if c == '(':
                stack.append(i)
            elif c == ')':
                if not stack:
                    remove.add(i)
                else:
                    stack.pop()
        
        for i in stack:
            remove.add(i)

        return ''.join([s[i] for i in range(len(s)) if i not in remove])
