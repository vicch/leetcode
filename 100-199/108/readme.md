# Problem

Given an array where elements are sorted in ascending order, convert it to a height-balanced BST.

A height-balanced binary tree is defined as a binary tree in which the depth of the two child trees of every node never differ by more than 1.

## Example

```
input  = [-10,-3,0,5,9]
output = [0,-3,9,-10,null,5] (one of all possible results)

     0
    / \
  -3   9
  /   /
-10  5
```

# Solution

For the BST to be balanced, naturally the root node should map to the middle element of the sorted array. Then recursively, the first half and the second half of the array are converted to the left and right child tree of the root.
