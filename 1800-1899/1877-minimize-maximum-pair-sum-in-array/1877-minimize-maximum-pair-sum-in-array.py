"""
In all possible ways of splitting the numbers into pairs, consider max(numbers), the way to minimize the global
max(sum(pair)) is to pair it with min(numbers), because any other combination will increase it.

With the current max(numbers) paired with min(numbers), the problem become recursively to pair max(numbers) of the
remaining numbers.

So basically we pair each current max(numbers) with min(numbers), and maintain and return the global max(sum(pair)).

Time complexity:
- O(nlogn + n) = O(nlogn), for sorting

Space complexity:
- O(1) if sorting in place
"""
class Solution(object):
    def minPairSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()
        max_sum = 0
        for i in range(len(nums) / 2):
            max_sum = max(nums[i] + nums[~i], max_sum)

        return max_sum
