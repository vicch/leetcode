"""
A typical prefix sum problem: store the prefix sum of the weights internally. Then for a random number that is
prefixSum[i-1] < random <= prefixSum[i], return i and weighted random index.

To look for i efficiently, as the prefix sums are monotonic, we can use upper bound binary search of the random value.

Time: O(n) for init, O(logn) for pick
Space: O(n)
"""
class Solution(object):

    def __init__(self, w):
        """
        :type w: List[int]
        """
        self.total = 0
        self.weights = []
        for weight in w:
            self.total += weight
            self.weights.append(self.total)

    def pickIndex(self):
        """
        :rtype: int
        """
        rand = random.randint(1, self.total)
        return self._getUpperBound(rand)

    def _getUpperBound(self, v):
        l, r = 0, len(self.weights) - 1
        while l <= r:
            m = (l + r) // 2
            if self.weights[m] < v:
                l = m + 1
            else:
                r = m - 1
        return l
