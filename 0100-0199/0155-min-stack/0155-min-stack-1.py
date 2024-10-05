"""
Keep a second stack to store the currently min value corresponding to the element in the main stack. By keeping the main
and min stacks in a 1:1 relation in terms of items count, they are always pushed and popped at the same time for sync.

1. Init stacks: main = [],         mins = []
2. Push:        main = [2],        mins = [2]         // 2 is currently the smallest value in main stack
3. Push:        main = [2, -1],    mins = [2, -1]     // compare with stack top (2), current min value is updated
4. Push:        main = [2, -1, 3], mins = [2, -1, -1] // compare with stack top (-1), current min value remains
5. Pop x 2:     main = [2],        mins = [2]         // currrent min reset to 2
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
        # Push the min value up to this point
        self.mins.append(self.mins[-1] if self.mins and self.mins[-1] < val else val)

    def pop(self):
        """
        :rtype: None
        """
        # Pop from both stacks
        self.mins.pop()
        self.nums.pop()

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
