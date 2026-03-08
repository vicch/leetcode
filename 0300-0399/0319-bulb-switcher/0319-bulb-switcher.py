"""
# Problem Type & Pattern

A mathematical number theory problem that reduces to counting perfect squares.

The key insight: bulb k is toggled once for every divisor of k. Numbers with an odd
number of divisors remain ON; only perfect squares have odd divisors because most
divisors pair (d, n/d), except when d = √n.

This is not an algorithmic optimization problem — it's a direct application of a
number theory property that collapses O(n²) simulation to O(1).

# Solution Explanation

## Step 1 - Understanding the Process

Each bulb i is toggled in round k if and only if k is a divisor of i.
Example: bulb 12 is toggled in rounds 1, 2, 3, 4, 6, 12 (its divisors).

So bulb i ends ON if it has an odd number of divisors, OFF if even.

## Step 2 - Number Theory Insight

Most numbers have divisors in pairs: (d, n/d).
Example: 12 has pairs (1,12), (2,6), (3,4) → 6 divisors (even).

The only time a divisor doesn't pair is when d = n/d → d² = n.
This happens only for perfect squares: 1, 4, 9, 16, ...

## Step 3 - Problem Reduction

Bulbs that remain ON are exactly those at perfect square positions.
Count perfect squares ≤ n.

That count is simply: ⌊√n⌋

## Step 4 - Direct Computation

No simulation needed. Just compute integer square root of n.

# Complexity

Time: O(1)
Space: O(1)

Direct mathematical computation; no loops or additional data structures.
"""

class Solution(object):
    def bulbSwitch(self, n):
        """
        :type n: int
        :rtype: int
        """
        import math
        return int(math.sqrt(n))
