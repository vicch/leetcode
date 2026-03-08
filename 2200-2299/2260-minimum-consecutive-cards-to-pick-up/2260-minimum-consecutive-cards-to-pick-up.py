"""
# Hash Map + Last Occurrence Pattern

This problem reduces to finding the minimum distance between any two equal values in the array. A sliding window approach might seem tempting due to its similarity with Minimum Window Substring (LeetCode 76), but it's overkill here — we only need to track when we see a duplicate and compute the interval directly.

While Minimum Window Substring requires maintaining complex state (frequency map, character counts, shrinking/growing), this problem has a much simpler requirement: just find the closest pair of equal values. A hash map storing the last occurrence index of each value gives us an O(n) solution with minimal bookkeeping.

# Solution Explanation

## Step 1 - Brute Force Idea

The most straightforward approach is to check every pair of cards: for each index i, look for the first card that matches it to the right, compute the distance, and track the minimum. This would be O(n²) time in the worst case (all cards distinct except one pair), and uses O(1) space.

## Step 2 - Key Insight

When we traverse the array from left to right, if we've seen a value before, we immediately know the distance to its most recent occurrence. We don't need to check all previous occurrences — the closest duplicate is always the one we saw last. This observation eliminates the O(n²) nested search.

## Step 3 - Last Occurrence Tracking

Maintain a hash map that stores the last index where each value appeared. When we encounter a value, if it's already in the map, compute the window size (current index - last index + 1) and update the global minimum. Then update the map with the current index. This ensures we always compare with the nearest previous occurrence.

# Complexity

Time: O(n) — single pass through the array
Space: O(n) — hash map stores at most n entries
"""

class Solution(object):
    def minimumCardPickup(self, cards):
        """
        :type cards: List[int]
        :rtype: int
        """
        last_seen = {}
        res = float('inf')

        for i, v in enumerate(cards):
            if v in last_seen:
                # Found a duplicate, compute the window size
                res = min(res, i - last_seen[v] + 1)
            # Update last occurrence
            last_seen[v] = i

        return res if res != float('inf') else -1
