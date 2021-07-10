# Problem

Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

## Example

```
input  = [
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
output = 11

The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11.
```

## Note

Bonus point if using only `O(n)` extra space, where `n` is the total number of rows in the triangle.

# Solution

This problem can be solved with Dynamic Programming. First try to find the transition function: from each number `(i,j)`, the path to the bottom row with minimum sum is `f(i,j) = min(f(i+1, j), f(i+1, j+1)) + (i,j)`.

So we can start from the base solution, i.e. the minimum sum of each number on the bottom row, and iterate all the way up till the top row.

To achieve `O(n)` extra space, we can store the minimum sum of each number of a certain row in the same array of size `n`, and overwrite the values from left to right when processing the row above.
