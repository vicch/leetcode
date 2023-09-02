"""
A naive solution is to look for the next higher temperature starting from each index, which is O(n^2) in worst case.

A better solution is that while iterating the list, we maintain a list of only temperatures that haven't seen a higher
temperature after it so far, and every time a temperature B higher than temperature A is seen, A is removed from the
list, and B is pushed.

The list is essentially a stack, to which temperatures are pushed and popped from one end.

An alternative is to iterate the list backwards, and maintain the list of "higher temperature candidates" for precedent
temperatures. For every temperature, look for its next warmer day from the list by popping till a higher temperature is
found, and push this temperature to it.

In both approaches, values in the list can be the indexes, because what we need is the distance between the current
index of iteration and the index in the list.

Time: O(n), because each index will be pushed and popped at most once, so it's O(2n) in worst case
Space: O(n)
"""
class Solution(object):
    def dailyTemperatures(self, temperatures):
        """
        :type temperatures: List[int]
        :rtype: List[int]
        """
        result = [0] * len(temperatures)
        stack = []

        for i, t in enumerate(temperatures):
            while len(stack) > 0 and t > temperatures[stack[-1]]:
                index = stack.pop()
                result[index] = i - index
            stack.append(i)

        return result