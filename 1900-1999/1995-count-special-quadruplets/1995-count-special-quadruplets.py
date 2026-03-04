"""
A typical two-sum pattern problem with clever reframing.

The key insight is rearranging the equation:
    nums[a] + nums[b] + nums[c] == nums[d]
    → nums[a] + nums[b] == nums[d] - nums[c]

This transforms a 4-sum into a 2-sum vs 2-sum structure.

Pattern: As we iterate c from left to right, maintain a hashmap of all valid
(a, b) pair sums where a < b < c. For each d > c, count how many pairs sum
to (nums[d] - nums[c]).

Adaptation:
- Iterate c as the "pivot" index
- For each c, first query all d > c against accumulated pair sums
- Then add new pairs (a, c) to the map for future iterations

Time complexity: O(n²)
Space complexity: O(n²) worst case for pair sums
"""

from collections import defaultdict


class Solution(object):
    def countQuadruplets(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        count = 0
        sums = defaultdict(int)

        # Initialize with the first valid pair (a=0, b=1)
        sums[nums[0] + nums[1]] = 1

        # c starts at 2 since we need a < b < c, and b must be at least 1
        for c in range(2, n - 1):
            # For each d > c, count pairs (a, b) where a+b = nums[d]-nums[c]
            for d in range(c + 1, n):
                count += sums[nums[d] - nums[c]]

            # Add new pairs (a, c) to the map for future iterations
            # These pairs will be valid (a, b) when c becomes someone's 'b'
            for a in range(c):
                sums[nums[a] + nums[c]] += 1

        return count
