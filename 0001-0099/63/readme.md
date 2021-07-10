# Problem

A robot is located at the top-left corner of a `m x n` grid. The robot can only move either down or right. The robot is trying to reach the bottom-right corner of the grid.

Now consider if some obstacles (marked as `1` in the input matrix) are added to the grids. How many unique paths would there be?

## Example

```
input  = [
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
output = 2
```

## Note

`m` and `n` will be at most 100.

# Solution

This can be solved by the bottom-up solution on problem #62. While populating the cell values, check if the cell is an obstacle, if it is, its value should be marked as 0 (instead of the sum of the cell below and on right side).
