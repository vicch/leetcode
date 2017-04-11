"""
Problem:
Design a stack that supports push, pop, top, and retrieving the minimum
element in constant time.
- push(x):  Push element x onto stack.
- pop():    Removes the element on top of the stack.
- top():    Get the top element.
- getMin(): Retrieve the minimum element in the stack.

Solution:
- Use an array and index to implement the main stack.
- Use another array and index to implement another stack containing the
  indices to minimum values.
"""

class MinStack(object):
    nums, mins

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.nums, self.mins = [], []


    def push(self, x):
        """
        :type x: int
        :rtype: void
        """
        self.nums.append(x)
        if !self.mins or x < self.nums[self.mins[-1]]
            self.mins.append(len(self.nums) - 1)
        

    def pop(self):
        """
        :rtype: void
        """
        if self.mins[-1] == len(self.nums) - 1:
            self.mins.pop()
        self.nums.pop()


    def top(self):
        """
        :rtype: int
        """
        return self.nums[-1]


    def getMin(self):
        """
        :rtype: int
        """
        return self.nums[self.mins[-1]]