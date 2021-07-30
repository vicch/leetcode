class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        cache = {}
        for n in nums:
            if n in cache:
                return True
            cache[n] = 1
        return False
