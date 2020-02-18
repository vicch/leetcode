# Problem

Given a binary tree, determine if it is a valid Binary Search Tree (BST):

- The left subtree of a node contains only nodes with values less than the node's value.
- The right subtree of a node contains only nodes with values greater than the node's value.
- Both the left and right subtrees must also be BST.

## Example 1

```
input  = [2, 1, 3]
output = true

  2
 / \
1   3
```

## Example 2

```
input  = [5,1,4,null,null,3,6]
output = false

  5
 / \
1   4
   / \
  3   6
```

# Solution

This is a typical binary tree problem that uses recursion. For each node:

- Check if this node's value is within the proper range (determined by its parent nodes).
- Check if its child nodes are BST.

The proper range of a node's value comes from the definition of BST:

- The min value of a right child node and its child nodes is the root node's value.
- The max value of a left child node and its child nodes is the root node's value.
