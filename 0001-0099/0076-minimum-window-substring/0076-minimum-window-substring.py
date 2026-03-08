"""
# Problem Type & Pattern

A classic sliding window problem. We need to find the minimum contiguous substring 
in S that contains all characters from T (including duplicates). The window expands 
and contracts based on character counts, shrinking from the left when all requirements 
are met to find the optimal size.

# Solution Explanation

## Step 1 - Brute Force Idea

For each starting index in S, expand the end index until the substring contains 
all characters from T (respecting duplicates), then track the smallest substring found.

This is O(N²) because for each start position we scan the rest of the string, and 
overlapping windows cause repeated work without reusing any information.

## Step 2 - Optimization Insight

Instead of restarting from every index, maintain a window [l, r] and slide it across 
the string. Only the border characters change when expanding or shrinking, so we can 
update character counts incrementally rather than recomputing from scratch.

This sliding window approach lets each character enter and leave the window at most once.

## Step 3 - Final Optimal Strategy

1. Track required character counts from T and maintain running counts in the current window.
2. Expand the right pointer to grow the window, incrementing counts. When a character's 
   count matches its required count, we've satisfied one more distinct requirement.
3. Once all requirements are met, shrink from the left while maintaining validity — update 
   the best window each time we successfully shrink without breaking validity.
4. When shrinking would break a requirement, stop and resume expanding the right pointer.

The key design is tracking "achieved" requirements — we only need to know how many distinct 
characters have met their count threshold, not the exact counts at every step.

## Complexity

Time: O(|S| + |T|) — each pointer traverses S at most once, and we build requiredCounts in O(|T|).
Space: O(1) — character counts are bounded by alphabet size (constant).
"""

class Solution(object):
    def minWindow(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        requiredCounts = Counter(t)
        windowCounts = defaultdict(int)

        required = len(requiredCounts)
        achieved = 0

        l, r = 0, 0
        lOptimal, rOptimal = -1, len(s)

        while r < len(s):
            rChar = s[r]
            windowCounts[rChar] += 1

            if rChar in requiredCounts and windowCounts[rChar] == requiredCounts[rChar]:
                achieved += 1

            while l <= r and achieved == required:
                if r - l < rOptimal - lOptimal:
                    lOptimal, rOptimal = l, r

                lChar = s[l]
                windowCounts[lChar] -= 1
                
                if lChar in requiredCounts and windowCounts[lChar] < requiredCounts[lChar]:
                    achieved -= 1
                
                l += 1
            
            r += 1
        
        return s[lOptimal:rOptimal+1] if lOptimal >= 0 else ""
