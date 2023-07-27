"""
It's really tempting to consider this as a combinations problem, where generate(n) becomes:
generate(1) * generate(n - 1) + generate(2) * generate(n - 2) + ...
But the combinations will contain duplidates, e.g. () + ()() = ()() + ()

It's actually a string generation process with backtracking:
- For each step, either a "(" or ")" can be attached to current string.
- "(" can be attached, unless there are already n of them.
- ")" can be attached, unless there are more or equal number of ")" than "(".
- Bottom is reached when there are n "(" and ")".
"""
class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        def generate(s, l, r):
            # Can be: len(s) == n * 2, because the values of l and r are checked and can never lead to invalid result.
            if l == n and r == n:
                result.append(s)
                return
            
            if l < n:
                generate(s + '(', l + 1, r)

            if r < l:
                generate(s + ')', l, r + 1)

        result = []
        generate('', 0, 0)

        return result
