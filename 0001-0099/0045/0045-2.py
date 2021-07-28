class Solution(object):
    def jump(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        # Take example input of [2, 3, 1, 1, 4], think of the indexes [0, 5] as being split into the ranges, so that for
        # each range N, it contains the indexes that can be reached with at least N jumps. So:
        # - Range 0 is [0, 0]
        # - Range 1 is [1, 2], because on the basis of previous range, the furthest index that can be reached is 2
        # - Range 2 is [3, 4], for the same reason as above
        # The question is basically finding which range the last position falls into. To do this, we iterate the
        # positions from start to end, and find the upper bound of each range (with upper bounds found, lower bounds
        # will be found natually), till the last position is covered in a range.

        jumps = 0
        # The upper bounds of the current 2 ranges
        curr_bound, next_bound = 0, 0

        for i, dist in enumerate(nums):
            # If the furthest position of taking another jump won't even reach current position, there is no solution
            if i > next_bound:
                return -1

            # If iterator has surpassed upper bound of current range, we have reached into the next range. Assign
            # next range to current range, and next range will move into the subsequent range. Range increment also
            # indicates another jump is taken.
            if i > curr_bound:
                jumps += 1
                curr_bound = next_bound

            # If after taking the jump, we can already reach the last position, a solution is found.
            if curr_bound >= len(nums) - 1:
                break

            # Extend upper bound of next range if we can just to a further position from a position of current range.
            next_bound = max(next_bound, i + dist)

        return jumps