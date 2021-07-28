class Solution(object):
    def jump(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # Recursively find the optimal jump to each position, starting from the last position
        return self.recur_jump(nums, len(nums) - 1)
    
    def recur_jump(self, nums, index):
        if index == 0:
            return 0

        # The optimal jump to each position should be the longest-possible jump to that position. It should be first
        # possible jump when trying from the furthest one (i.e. index 0) to the closest one (i.e. current index - 1).
        start = 0
        while nums[start] < index - start:
            start += 1

        return self.recur_jump(nums, start) + 1

s = Solution()
print(s.jump([1]))
print(s.jump([2,3,1,1,4]))
print(s.jump([2,3,0,1,4]))
