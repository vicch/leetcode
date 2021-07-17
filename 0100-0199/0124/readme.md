# Problem

Given a non-empty binary tree, find the maximum path sum.

A path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node, but does not need to go through the root.

## Example 1

```
input  = [1,2,3]
output = 6

  1
 / \
2   3

path = 2->1->3
```

## Example 2

```
input  = [-10,9,20,null,null,15,7]
output = 42

 -10
 / \
9  20
  /  \
 15   7

path = 15->20->7
```

# Solution

The path of max sum will be a subtree of the input tree. Any node in the subtree is either:

- 1st type: the root of the subtree
- 2nd type: a node on the path from the root node of the subtree to a bottom node of the subtree

If the nodes are visited from top to bottom, there will be repeated calculations. The right way is to visit the nodes from bottom up (DFS).

When visiting each node, we should:

1. Return the max sum of all the paths that start from this node and end on one of its child nodes, because if this node is the 2nd type of node, then this sum is part of the final result.
2. Check if this node can be the 1st type, this can be done by comparing these 2 values: the current max sum, and the sum of "this node + max sum of its left child node + max sum of its right child node". The "max sum of its left/right node" is just the return value when visiting its left/right node.