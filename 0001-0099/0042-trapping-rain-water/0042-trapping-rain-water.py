"""
The key is to find the formula of any index's watermark_height = min(left_max_height, right_max_height),
where left_max_height is the highest elevation on the left of current index, and vice versa. With the watermark height,
the water volume at this index = watermark_height - current_height

By using 2 pointers, and always move the pointer that has lower elevation towards the center, it is guaranteed that the
current max height on the side of the pointer is "the shorter piece of the bucket".
"""
class Solution(object):
    def trap(self, height):
        if not height:
            return 0

        left, right = 0, len(height) - 1
        lmax = rmax = water = 0

        while left < right:
            if height[left] < height[right]:
                if height[left] >= lmax:
                    lmax = height[left]
                else:
                    # lmax must be lower than height[right], otherwise the right pointer will be moving, instead of
                    # left pointer, so this can be simplified as (lmax - height[left])
                    water += (min(lmax, height[right]) - height[left])
                left += 1
            else:
                if height[right] >= rmax:
                    rmax = height[right]
                else:
                    # Same as above, this can be simplified as (rmax - height[right])
                    water += (min(height[left], rmax) - height[right])
                right -= 1

        return water
