"""
Problem:
Implement a basic calculator to evaluate a simple expression string. The
expression string may contain open ( and closing parentheses ), the plus +
or minus sign -, non-negative integers and empty spaces. Assume that the
given expression is always valid.

Example:
"(1+(4+5+2)-3)+(6+8)" = 23

Solution:
Expand the expression by evaluating all numbers and add up later. Numbers are
evaluated as positive or negative depending on a "sign" which negates when
minus operator is encountered. For example, 1 - (2 - (3 - 4)), numbers added
to the list are: 1, -2, 3, -4.
"""

class Solution(object):
    def calculate(self, s):
        """
        :type s: str
        :rtype: int
        """
        i, total = 0, 0
        signs = [1, 1]

        while i < len(s):
            if s[i].isdigit():
                j = i
                while i < len(s) and s[i].isdigit():
                    i += 1
                total += signs.pop() * int(s[j:i])
                i -= 1 # To cancel out the +=1 at the end of while body
            elif s[i] == ')':
                signs.pop()
            elif s[i] in '+-(':
                signs.append(signs[-1] * (1, -1)[s[i] == '-'])
            i += 1

        return total

tests = [
    ' 2-1 + 2 ',
    '(1+(4+5+2)-3)+(6+8)',
    '10',
    '11 + (12 - 13) + 14',
    '1-(5)',
    '3-(5+1)',
    '2-(5-6)',
    '1 - (2 - (3 - 4)) - (5 - 6)',
    '1 + (3 - (4 + 10 - (2 + 0) - (3 + 4) - (4 - 5))) - (2 - 3)'
]
solution = Solution()
for test in tests:
    print solution.calculate(test)