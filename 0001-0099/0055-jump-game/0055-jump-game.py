"""
Consider DP from bottom up: on each step, the local max reachable step is current step plus current step's max jump
distance. Compare this with the current global max reachable step, and update the global value if local one is bigger.

If on any step, the max reachable cannot reach current step, then there is no way to jump any further.

At the end, check if the last step is reachable.
"""
class Solution(object):
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        reachable = 0

        for i, dist in enumerate(nums):
            if i > reachable:
                break
            reachable = max(reachable, i + dist)

        return reachable >= len(nums) - 1
