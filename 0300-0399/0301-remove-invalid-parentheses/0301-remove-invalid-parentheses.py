"""
Instead of considering the problem as removal of parentheses, consider the input as a stream of chars (of letters and
parentheses), and by keeping or ignoring the chars, how many unique strings with valid parentheses can be built.

To guarantee that the result string is valid, and ignoring only necessary number of chars, at any point, there is a
number of parentheses to close subsequently, and there is a limit of extra chars that can be ignored subsequently.

For each parenthese in the stream, there are 2 options: either keep it or ignore it.
- If it's opening parenthese
    - If keeping it, then for next char, toClose increments by 1
    - If ignoring it, then for next char, toRemove decrements by 1
- If it's closing parenthese
    - If keeping it, then for next char, toClose decrements by 1
    - If ignoring it, then for next char, toRemove decrements by 1

The min number of parentheses to remove can be counted by iterating and validating the string first, via running counts
of currently opened parentheses, and closing parentheses that have no matching opening parenthese.

To elimate repeated work, use a DP + mem approach, and consider the tuple of (index, toClose, toRemove) as key, and
the list of valid strings starting from the index as value. Ultimately, the global problem has key (0, 0, toRemove).

Time: O(2^n) for worst case where each parenthese has 2 options.
Space: ?
"""
class Solution(object):
    def removeInvalidParentheses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        # Init DP cache.
        mem = {(len(s), 0, 0): [""]}
        
        def helper(key):
            if key in mem:
                return

            offset, toClose, toRemove = key

            # Find the next char that is parenthese, all chars in-between are static and kept.
            i = offset
            while i < len(s) and s[i].isalpha():
                i += 1
            prefix = s[offset:i]

            # If there is no more parenthese, check if there is any parenthese to close. If yes, then there is no valid
            # string, otherwise these is only 1 valid string which is the remaining part itself.
            if i == len(s):
                if toClose > 0:
                    mem[key] = []
                else:
                    mem[key] = [prefix]
                return

            options = []
            if s[i] == '(':
                # If keep it, DP next level and populate options.
                subKey = (i + 1, toClose + 1, toRemove)
                helper(subKey)
                options.extend([prefix + '(' + option for option in mem[subKey]])
                # If remove it when possible.
                if toRemove > 0:
                    subKey = (i + 1, toClose, toRemove - 1)
                    helper(subKey)
                    options.extend([prefix + option for option in mem[subKey]])
            else:
                # If keep it.
                if toClose > 0:
                    subKey = (i + 1, toClose - 1, toRemove)
                    helper(subKey)
                    options.extend([prefix + ')' + option for option in mem[subKey]])
                # If remove it.
                if toRemove > 0:
                    subKey = (i + 1, toClose, toRemove - 1)
                    helper(subKey)
                    options.extend([prefix + option for option in mem[subKey]])

            mem[key] = set(options)

        # Count the min number of parentheses to remove to make the string valid.
        opening, toRemove = 0, 0
        for c in s:
            if c.isalpha():
                continue
            if c == '(':
                opening += 1
            else:
                if opening == 0:
                    toRemove += 1
                else:
                    opening -= 1
        # The number of remaining opening parentheses + the number of closing parentheses that have no opening.
        toRemove += opening

        if toRemove == 0:
            return [s]

        key = (0, 0, toRemove)
        helper(key)
        return mem[key]
