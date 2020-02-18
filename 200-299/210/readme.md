# Problem

There are a total of `n` courses you have to take, labeled from `0` to `n-1`.

Some courses may have prerequisites, for example to take course `0` you have to first take course `1`, which is expressed as a pair `[0,1]`.

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

## Example 1

```
Input  = 2, [[1,0]]
Output = [0,1]
```

## Example 2

```
Input  = 4, [[1,0],[2,0],[3,1],[3,2]]
Output = [0,1,2,3] or [0,2,1,3]
```

## Note

- The input prerequisites is a graph represented by a list of edges, not adjacency matrices.
- You may assume that there are no duplicate edges in the input prerequisites.

# Solution

This problem is essentially the same as #207, and topological sorting can be used here as well. Refer to solution of #207.
