"""
This is a stateful reachability problem where state = (stone position, last jump length).
Unlike classic stairs DP where we only track reachable steps, here we must track which k
values were used to reach each stone because next jumps depend on the previous k.

Key insight: Reaching the same stone with different k values produces different futures.
Example: reaching stone 10 with k=2 allows next jumps of 1,2,3, but reaching it with
k=4 allows next jumps of 3,4,5. So state must include (position, k).

DP approach: dp[stone] = set of k values that can reach this stone. Process stones
sequentially, propagate k-1,k,k+1 jumps to valid next stones. Stop when we can reach
the last stone.

Time: O(n²) - for each of n stones, we iterate through at most n possible k values
Space: O(n²) - worst case we store O(n) k values for each of n stones
"""
class Solution(object):
    def canCross(self, stones):
        """
        :type stones: List[int]
        :rtype: bool
        """
        # Map stone position to its index for O(1) lookup
        stone_to_idx = {pos: i for i, pos in enumerate(stones)}

        # dp[i] = set of k values that can reach stone i
        dp = [set() for _ in range(len(stones))]
        dp[0].add(0)  # Start at first stone with last jump = 0

        for i in range(len(stones)):
            for k in dp[i]:
                # Try jumps of k-1, k, k+1 (skip if jump <= 0)
                for jump in [k-1, k, k+1]:
                    if jump <= 0:
                        continue

                    next_pos = stones[i] + jump
                    if next_pos in stone_to_idx:
                        next_idx = stone_to_idx[next_pos]
                        dp[next_idx].add(jump)

                        # Early exit if we can reach the last stone
                        if next_idx == len(stones) - 1:
                            return True

        return len(dp[-1]) > 0
