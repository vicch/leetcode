# Problem

Given an integer array, find the contiguous subarray (containing at least one number) which has the largest sum and return it.

## Example

```
input  = [-2,1,-3,4,-1,2,1,-5,4]
output = 6

Subarray [4,-1,2,1] has the largest sum = 6.
```

# Solution

O(n) time, O(1) space.

This is an optimization problem. Firstly break down into a smaller problem: each subarray has to end on a certain element, so "the max sum of all subarrays ending on any element" is the max of "the max sum of all subarrays ending on a certain element".  In other words:

```
if f(k) = max sum of all subarrays ending on element k
then max sum of all = max(f(0), f(1), ... f(n))
```

For each element `k`, if it's in the final subarray, it is either

- a continuation of a subarray started before it, or
- the first element of a subarray.

We should compare these 2 cases, and keep the one that can result in a bigger sum. So with `f(k - 1)`, we can deduce the transition function for `f(k)`:

```
f(k) = max(f(k - 1) + nums[k], nums[k])
           |                   |
           |                   +- If element k starts a new subarray
           + If element k continues a previous subarray
```

With `f(0)` is already known, which is just `nums[0]`, we can calculate each `f(k)`, and while doing so, maintain the max value of all `f(k)` so far. After all elements are visited, this maintained value will contain the final answer.
