"""
There are several scenarios when inserting a number in existing sequence:

1. Insert 3 into empty sequence, then 3 becomes its own union, with length 1.
2. Insert 3 into [1/2, ...], then 1/2/3 becomes new union, with length 3.
3. Insert 3 into [1/2, 4/5, ...], then 1/2/3/4/5 becomes new union, with length 5.

We only need to have the union's latest length accessible on the edges, because those are the only places where the
union can extend, i.e. where the actual length of the union is needed. E.g. when inserting 3 into 4/5/6..., we get the
length of that union on number 4, then after insertion of 3, the union becomes 3/4/5/6... and number 3 carries the new
length of the union.
"""

class Solution(object):
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # Dedup
        nums = set(nums)
        maxLen, lens = 0, {}

        for n in nums:
            # Get lengths of adjacent unions, 0 means no union on that side
            l, r = lens.get(n-1, 0), lens.get(n+1, 0)
            # New union length with current number inserted
            curLen = l + r + 1
            # Update union lengths to the new union's edges. If there is no union on one side, l or r is 0, then current
            # number's union length is updated, because it's the new edge of the union (on the other side)
            lens[n-l], lens[n+r] = curLen, curLen
            maxLen = max(maxLen, curLen)

        return maxLen
