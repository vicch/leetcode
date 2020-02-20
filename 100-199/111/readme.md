# Problem

Given a binary tree, find its minimum depth. The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

## Example

```
input  = [3,9,20,null,null,15,7]
output = 2

  3
 / \
9  20
  /  \
 15   7
```

# Solution

## DFS

The minimum depth of any root node should be the smaller one of the minimum depths of its left and right child trees. But note the edge case when the left or right child tree is empty, in this case the minimum depth is not counted as 0, it is ignored instead.

## BFS

The DFS approach is less efficient when the tree is very unbalanced. To optimize it, we can do BFS and stop the traversal when the first leave node is found.

To maintain the current depth, we need to know when the right-most node (assuming the BFS is from left to right) is visited for each level, then the depth should be incremented after this node. The right-most node is recursive: current level's right-most node's child node (right child node, or left child node if right child node not exist) is the right-most node of next level.
