"""
As defined, the process is basically:

- Push all numbers to a stack.
- When an operator is met, pop 2 operands (note the ordering) and do the calculation, then push result back to stack.

Continue till all tokens are consumed. Remaining value in stack is final result.
"""

class Solution(object):
    def evalRPN(self, tokens):
        """
        :type tokens: List[str]
        :rtype: int
        """
        operators = ["+", "-", "*", "/"]
        stack = []

        for t in tokens:
            # When meeting an operator, pop 2 operands, do the calculation, and push result back
            if t in operators:
                b = stack.pop()
                a = stack.pop()

                if t == "+":
                    a += b
                elif t == "-":
                    a -= b
                elif t == "*":
                    a *= b
                else:
                    # Python division between int always truncate, e.g. -3 / 2 = -2 (-1.5 truncate to -2)
                    # But this problem requires negative values be rounded to the next int, e.g. -3 / 2 = -1
                    # Convert to float then back to int can achieve this logic
                    a = int(float(a) / b)

                stack.append(a)

            # Otherwise push number to stack
            else:
                stack.append(int(t))

        return stack.pop()
