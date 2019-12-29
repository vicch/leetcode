# Problem

There are a total of `n` courses you have to take, labeled from `0` to `n-1`.

Some courses may have prerequisites, for example to take course `0` you have to first take course `1`, which is expressed as a pair `[0,1]`.

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

## Example 1

```
Input  = 2, [[1,0]]
Output = true
```

## Example 2

```
Input  = 2, [[1,0],[0,1]]
Output = false
```

## Note

- The input prerequisites is a graph represented by a list of edges, not adjacency matrices.
- You may assume that there are no duplicate edges in the input prerequisites.

# Solution

The courses can be represented by a directed graph, and the problem is equivalent of detecting if there is a cycle in the graph.

The problem can then solved by using [topological sorting](https://en.wikipedia.org/wiki/Topological_sorting):

1. Transform the pair `[a, b]` to adjacency list `b => [a, ...]`, where `a` is the course and `b` is the prerequisite.
2. Calculate the indegrees of each node, in other words how many prerequisites each course has.
3. Look for the first node that has `0` indegree, which means this course can be taken at this step. For convenience, set the indegree of this course to a non-zero value, e.g. `-1`, so the next loop will skip it.
4. Remove the indegree by `1` for all the courses that have this course as prerequisite.
5. Go back to step 3 and look for the next node with `0` indegree. This should loop exactly `n` times, which means all courses are taken. If at any loop we can't find a node with `0` indegree, it means the process if stuck because there is a cycle in the graph.