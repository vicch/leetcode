"""
Similar to the previous solution, but optimizing the min stack, by deduplicating and only pushing when a new smaller or
equal value is pushed. Then pop the min stack when the element being popped from the main stack equals to the top of the
min stack.

This works for duplicate elements, as the min stack will also contain duplicate elements if it's equal to the currently
min value.

The logic is slightly more complex, but space complexity is reduced.
"""

class MinStack(object):

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.nums, self.mins = [], []

    def push(self, val):
        """
        :type val: int
        :rtype: None
        """
        self.nums.append(val)
        # Push to min stack if it's smaller or equal to current min value
        if not self.mins or self.mins[-1] >= val:
            self.mins.append(val)

    def pop(self):
        """
        :rtype: None
        """
        val = self.nums.pop()
        # Pop from min stack if the top matches the value popped from main stack
        if self.mins and self.mins[-1] == val:
            self.mins.pop()

    def top(self):
        """
        :rtype: int
        """
        return self.nums[-1] if self.nums else None

    def getMin(self):
        """
        :rtype: int
        """
        return self.mins[-1] if self.mins else None
