# Problem

Given a binary tree, find its maximum depth. The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

## Example

```
input  = [3,9,20,null,null,15,7]
output = 3

  3
 / \
9  20
  /  \
 15   7
```

# Solution

This is a recursive problem: the max depth of a `root` node equals to the bigger value between its `left` and `right` child tree's max depth plus 1 (`root` node's own depth).

So it can be solved recursively.
