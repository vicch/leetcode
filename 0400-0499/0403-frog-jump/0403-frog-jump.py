"""
Stateful reachability where state = (stone position, last jump length). Unlike classic
stairs DP, we must track which k values were used to reach each stone because next
jumps depend on the previous k.

Two pruning tricks that make this problem much easier:
1. Early impossibility check: if stones[i] - stones[i-1] > i, impossible to reach stone i
   (max jump at position i cannot exceed i, since jumps increase at most by +1)
2. Only consider positive jumps (k-1, k, k+1 where jump > 0)

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
        # Pruning 1: early impossibility check
        # At stone i, max possible jump cannot exceed i (jumps increase at most by +1)
        for i in range(1, len(stones)):
            if stones[i] - stones[i-1] > i:
                return False

        # Use set for O(1) stone existence check
        stone_set = set(stones)

        # dp[stone] = set of jump sizes that can reach this stone
        dp = {stone: set() for stone in stones}
        dp[0].add(0)

        last_stone = stones[-1]

        for stone in stones:
            for k in dp[stone]:
                # Pruning 2: only consider positive jumps
                for jump in (k-1, k, k+1):
                    if jump <= 0:
                        continue

                    next_pos = stone + jump

                    # Early exit if we can reach the last stone
                    if next_pos == last_stone:
                        return True

                    if next_pos in stone_set:
                        dp[next_pos].add(jump)

        return False
