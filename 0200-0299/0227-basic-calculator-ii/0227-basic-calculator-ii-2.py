"""
Adjusting the 1st solution: instead of parsing all numbers and operators separately, just iterate the string once,
while parsing and maintaining processed values. For each parsed number, check the last operator before it:
- For "+", simply append the value to stack, to be summed at the end.
- For "-", append the negated value to stack.
- For "*", pop and append multiplication of the two.
- For "/", pop and append division of the two.
"""
class Solution(object):
    def calculate(self, s):
        """
        :type s: str
        :rtype: int
        """
        stack = []

        num = 0
        lastop = '+'

        # A trick to append a "+" at the end of the string, so the last number can be handled correctly.
        for c in s + '+':
            # Skip whitespaces.
            if c.isspace():
                continue

            # Accumulate current number.
            if c.isdigit():
                num = num * 10 + ord(c) - ord('0')
                continue
            
            if lastop == '+':
                stack.append(num)
            elif lastop == '-':
                stack.append(-num)
            elif lastop == '*':
                stack.append(stack.pop() * num)
            elif lastop == '/':
                v = stack.pop()
                # Handle truncation of positive/negative values.
                stack.append(abs(v) / num * (1 if v > 0 else -1))

            # If it reaches here, it means current char is operator. Reset the number for next operand.
            num = 0
            lastop = c
            
        return sum(stack)
