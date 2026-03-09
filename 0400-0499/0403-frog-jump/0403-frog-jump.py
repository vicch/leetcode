"""
# Problem Type & Pattern

Stateful reachability with multi-state DP where the state includes transition history.
Unlike classic "stairs" or "reachability" DP problems where state = step position only,
this problem requires tracking (stone_position, last_jump) because the frog's next
jump depends on its previous jump length. This transforms the problem from simple
reachability to stateful graph reachability.

The pattern: when future transitions depend on how you arrived at the current state,
you must include that arrival information in your DP state.

# Solution Explanation

## Step 1 - Why Classic Reachability Fails

In a standard "climbing stairs" DP problem:
- State = step position
- Transitions = fixed step sizes (+1, +2)
- `reachable[i]` boolean suffices

For Frog Jump:
- Next jump depends on previous jump k: {k-1, k, k+1}
- Reaching the same stone with different k values leads to different futures
- Example: Stone at 10 reached with k=2 vs k=4 → different next jumps available

Therefore, the state must be `(stone_position, last_jump)`, not just `stone_position`.

## Step 2 - Graph Interpretation

Model this as a graph reachability problem:
- Nodes: `(stone_index, last_jump)` pairs
- Edges: from state k → {k-1, k, k+1} jumps
- If `stones[i] + jump` exists, transition to `(target_stone, jump)`
- Goal: Reach any state where position == last stone

This framing makes the BFS/DP relationship clear.

## Step 3 - DP State Representation

Instead of explicit BFS queue with (pos, k) pairs, the efficient structure is:
- `dp[stone]` = set of k values that can reach this stone
- Example: stone 3: {2} means we can reach stone 3 with a last jump of 2
- Starting state: dp[0] = {0}

This allows constant-time transitions and avoids queue overhead.

## Step 4 - State Transitions

For each reachable (stone, k):
- Generate candidate jumps: {k-1, k, k+1}
- For each jump > 0 (negative/zero jumps invalid):
  - `next_pos = stone + jump`
  - If `next_pos` exists in stone_set, add jump to `dp[next_pos]`
- If `next_pos` is the last stone, return True immediately

## Step 5 - Pruning Optimizations

Two key observations that dramatically reduce state space:

1. Early impossibility check:
   - At stone i, maximum possible jump cannot exceed i (jumps grow at most by +1)
   - If `stones[i] - stones[i-1] > i`, return False
   - This O(n) check eliminates many impossible cases before DP runs

2. Only consider positive jumps:
   - From k → {k-1, k, k+1}, keep only `jump > 0`
   - Zero/negative jumps are invalid moves forward

# Complexity

Time: O(n²) worst case — for each of n stones, iterate through at most n possible k values.
In practice, pruning makes this much smaller.

Space: O(n²) worst case — store up to n k values for each of n stones.
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
