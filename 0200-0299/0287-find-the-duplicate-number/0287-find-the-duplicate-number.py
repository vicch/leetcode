"""
O(1) space can be achieved with reversible in-place mods. The values can be considered as indice of the list. If all
values are unique, then by visiting the indice, each index should be visited once. If one index is visited more than
once, it must be the duplicate value.

To mark the visit with O(1) space, flip the value to negative for each visit, then if any visit meets a negative value,
it's a duplicate visit.

All flipped values can be restored with an iteration in the end.

Time: O(n)
Space: O(1)
"""
class Solution(object):
    def findDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        dup = None
        for n in nums:
            i = abs(n)
            if nums[i] < 0:
                dup = abs(n)
                break
            else:
                nums[i] = -nums[i]
        
        for i, n in enumerate(nums):
            nums[i] = abs(n)

        return dup
