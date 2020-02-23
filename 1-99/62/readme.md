# Problem

A robot is located at the top-left corner of a `m x n` grid. The robot can only move either down or right. The robot is trying to reach the bottom-right corner of the grid.



How many possible unique paths are there?

## Example 1

```
m = 7, n = 3
output = 28

╔═══╦═══╦═══╦═══╦═══╦═══╦═══╗
║ S ║   ║   ║   ║   ║   ║   ║
╠═══╬═══╬═══╬═══╬═══╬═══╬═══╣
║   ║   ║   ║   ║   ║   ║   ║
╠═══╬═══╬═══╬═══╬═══╬═══╬═══╣
║   ║   ║   ║   ║   ║   ║ F ║
╚═══╩═══╩═══╩═══╩═══╩═══╩═══╝
```

## Note

`m` and `n` will be at most 100.

# Solution

## Backtracking

We can infer these 2 rules from the problem definition:

- Because it can only move down or right, when it reaches the bottom row or right-most column, there will be only 1 path to the end.
- For every cell, the number of paths from it to the end equals to the sum of paths from the cells below it and to its right.

Write these in the table, each cell contains the number of paths from it to the end:

```
╔═══╦═══╦═══╦═══╦═══╦═══╦═══╗
║   ║   ║   ║   ║   ║ 3 ║ 1 ║
╠═══╬═══╬═══╬═══╬═══╬═══╬═══╣
║   ║   ║   ║   ║ 3 ║ 2 ║ 1 ║
╠═══╬═══╬═══╬═══╬═══╬═══╬═══╣
║ 1 ║ 1 ║ 1 ║ 1 ║ 1 ║ 1 ║ 0 ║
╚═══╩═══╩═══╩═══╩═══╩═══╩═══╝
```

So to get the number of paths starting from cell `(0,0)`, we can recursively get the number of paths it depends on:

```
f(0,0) = f(1,0)          + f(0,1)
       = f(2,0) + f(1,1) + f(1,1) + f(0,2)
       = ...
```

Then it reachs the bottom row or right-most column (where the paths are already known), we can backtrack the results to the starting point.

Note that many cells are calculated repeatedly, this can be optimizez by memorization (store the temp results in an array).

## Bottom-up

Based on the table in backtracking solution, we can populate the cells one by one (the bottom row and right-most column are pre-populated with 1s) with the number of paths starting from this cell, then return the value in the top-left cell.

## Combination

For a `m x n` grid, no matter what path it is, it must be a combination of `m - 1` moves to the right side and `n - 1` moves to the down side.

So the problem becomes: how many ways can `m - 1` (or `n - 1`) items be arranged among `m + n - 1` items.
