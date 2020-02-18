# Problem

Find the sum of all left leaves in a given binary tree.

## Example

```
  3
 / \
9  20
  /  \
 15   7

result = 9 + 15 = 24
```

# Solution

If current tree's left node is a leaf, return its value. Otherwise get sum of left and right child trees recursively.
