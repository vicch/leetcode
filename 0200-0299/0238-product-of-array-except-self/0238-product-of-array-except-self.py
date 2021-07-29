class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """

        # Consider array [1, 2, 3, 4], the calculation of products array is basically:
        #
        #                      1  -+
        #                   1  2   |
        #                1  2  3  -+- The "left hand" numbers multiplied incrementally
        # products = [_, _, _, _]
        #             2  3  4     -+
        #             3  4         |
        #             4           -+- The "right hand" numbers multiplied incrementally
        #
        # By "incrementally" it means: 2 x 3 x 4 = (3 x 4) x 2, so if the result of 3 x 4 is already in a variable, it
        # only needs to multiply by 2 to get the next value, and so on.
        #
        # So with 2 rounds (one for "left hand" numbers and one for "right hand" numbers) of incremental multiplication,
        # the products array can be obtained.

        products = [1] * len(nums)

        # Multiply "left hand" numbers
        accum = 1
        for i in range(1, len(nums)):
            accum *= nums[i - 1]
            products[i] *= accum
            # As product[i - 1] if just the accumulated value of last loop, the use of "accum" can be avoided by:
            # products[i] = products[i - 1] * nums[i - 1]

        # Multiple "right hand" numbers
        accum = 1
        for i in range(len(nums) - 2, -1, -1):
            accum *= nums[i + 1]
            products[i] *= accum

        return products
