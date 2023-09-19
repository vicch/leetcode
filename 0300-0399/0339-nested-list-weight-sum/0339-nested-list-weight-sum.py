"""
A typical DFS + recursion problem. Pass down the list and depth to lower level, and pop up the calculated sum to upper
level.

Time: O(n), n being the number of nested elements (integer or list), as each element is processed once
Space: O(n), in worst case of a single  [[[...]]], the recursion stack takes O(n) space
"""
# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
#class NestedInteger(object):
#    def __init__(self, value=None):
#        """
#        If value is not specified, initializes an empty list.
#        Otherwise initializes a single integer equal to value.
#        """
#
#    def isInteger(self):
#        """
#        @return True if this NestedInteger holds a single integer, rather than a nested list.
#        :rtype bool
#        """
#
#    def getInteger(self):
#        """
#        @return the single integer that this NestedInteger holds, if it holds a single integer
#        Return None if this NestedInteger holds a nested list
#        :rtype int
#        """
#
#    def getList(self):
#        """
#        @return the nested list that this NestedInteger holds, if it holds a nested list
#        Return None if this NestedInteger holds a single integer
#        :rtype List[NestedInteger]
#        """

class Solution(object):
    def depthSum(self, nestedList):
        """
        :type nestedList: List[NestedInteger]
        :rtype: int
        """
        return self._dfs(nestedList, 1)

    def _dfs(self, nestedList, depth):
        sum = 0
        for elem in nestedList:
            if elem.isInteger():
                sum += elem.getInteger() * depth
            else:
                sum += self._dfs(elem.getList(), depth+1)
        return sum
