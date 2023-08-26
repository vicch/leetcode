"""
Binary search to find a certain amount. It's a search of upper bound instead of exact match. The tricky part is the
boundary conditions and the "binary" approach.

Time: O(n * logm), n is number of piles, m is search space
Space: O(1)
"""
class Solution(object):
    def minEatingSpeed(self, piles, h):
        """
        :type piles: List[int]
        :type h: int
        :rtype: int
        """
        def computeHours(k):
            # List comprehension is more compact, but takes O(n) space.
            hours = 0
            for p in piles:
                hours += math.ceil(1.0 * p / k)
            return hours

        l, r = 1, max(piles)

        # End search if the pointers cross, instead of touching.
        while l < r:
            m = (l + r) // 2
            hours = computeHours(m)

            if hours <= h:
                # Move right to middle, instead of pass middle.
                r = m
            else:
                l = m + 1
        
        return r
