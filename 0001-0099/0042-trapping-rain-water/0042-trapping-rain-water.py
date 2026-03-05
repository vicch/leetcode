"""
A classic two-pointer problem that exploits a greedy invariant.

**Pattern Recognition:**
- The problem asks about water trapped between "walls" — immediately suggests tracking boundaries
- Brute force would be O(n²) (scan left+right for each index) — screams optimization
- Water formula `min(maxLeft, maxRight) - height[i]` is the key insight

**Core Insight:**
The shorter boundary determines the water level. When `height[left] < height[right]`, we know the right side is at least as tall as the left boundary, so water at `left` is limited solely by `lmax`. We can finalize left and move the pointer.

**Thought Process:**

1. **Understanding the Physics**
   Water at any index = min(tallest wall left, tallest wall right) - current height.

2. **Brute Force (O(n²))**
   Scan left+right for each index to find boundaries. Too slow.

3. **Precompute Arrays (O(n) time, O(n) space)**
   - `leftMax[i] = max(height[0..i])`
   - `rightMax[i] = max(height[i..n-1])`
   - Third pass calculates water. Good, but wasteful.

4. **Two-Pointer (O(n) time, O(1) space)**
   Track `lmax` and `rmax` on the fly. Process the side with smaller current height because:
   - If `height[left] < height[right]`, right boundary is taller
   - Water at left is limited by `lmax` — we can finalize and move left++

Time complexity: O(n)
Space complexity: O(1)
"""

class Solution(object):
    def trap(self, height):
        if not height:
            return 0

        l, r = 0, len(height) - 1
        lmax, rmax, total = 0, 0, 0

        while l < r:
            lmax = max(lmax, height[l])
            rmax = max(rmax, height[r])

            if height[l] < height[r]:
                # lmax limits water at left — right side is guaranteed at least as tall
                total += lmax - height[l]
                l += 1
            else:
                # rmax limits water at right — left side is guaranteed at least as tall
                total += rmax - height[r]
                r -= 1

        return total
