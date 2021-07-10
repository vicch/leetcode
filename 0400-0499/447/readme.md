# Problem

Given `n` points in the plane that are all pairwise distinct, a "boomerang" is a tuple of points `(i, j, k)` such that the distance between `i` and `j` equals the distance between `i` and `k` (the order of the tuple matters).

Find the number of boomerangs. You may assume that `n` will be at most 500 and coordinates of points are all in the range [-10000, 10000] (inclusive).

## Example

```
input  = [[0,0],[1,0],[2,0]]
output = 2

The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]
```

# Solution

Assuming among all the points, there are `x` points with distance `y` to the point `i`, it will form `x (x - 1)` different boomerangs (because `j` has `x` options, then `k` has `x - 1` options).

So the problem is actually, for every point `i`, grouping all other points based on their distances to `i`, and check how many points fall into each slot.
