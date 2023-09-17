"""
Because multiplication and division have high priority, it's natural to put operands in a stack and push/pop when "*"
or "/" operator is met. And the stack in this case contains all operands for addition and subtraction, which can be
processed after the string reaches the end. To simplify the process, we can push negative values when a "-" is met.

Time: O(n)
Space: O(n)
"""
class Solution(object):
    def calculate(self, s):
        """
        :type s: str
        :rtype: int
        """
        nums, ops = self._parse(s)

        # First value is pushed directly.
        stack = [nums[0]]

        for i, op in enumerate(ops):
            if op == '+':
                stack.append(nums[i+1])
            elif op == '-':
                stack.append(-nums[i+1])
            elif op == '*':
                v = stack.pop() * nums[i+1]
                stack.append(v)
            elif op == '/':
                v = stack.pop()
                # Division should round down for positive number, and round up for negative number, so for simplicity,
                # always divide positive value and restored the sign accordingly.
                v = abs(v) / nums[i+1] * (1 if v > 0 else -1)
                stack.append(v)
            else:
                continue
        
        return sum(stack)
    
    """
    Parse the numbers and operators in one go.
    """
    def _parse(self, s):
        nums = []
        ops = []

        i = 0
        while i < len(s):
            if s[i] == ' ':
                i += 1
            elif s[i].isnumeric():
                # Find the end of current number.
                j = i
                while j < len(s) and s[j].isnumeric():
                    j += 1
                nums.append(int(s[i:j]))
                i = j
            else:
                ops.append(s[i])
                i += 1

        return nums, ops
        