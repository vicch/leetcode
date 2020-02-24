# Problem

Given a binary tree, determine if it is height-balanced.

A height-balanced binary tree is a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

## Example 1

```
input  = [3,9,20,null,null,15,7]
output = true

  3
 / \
9  20
  /  \
 15   7
```

## Example 2

```
input  = [1,2,2,3,3,null,null,4,4]
output = false

      1
     / \
    2   2
   / \
  3   3
 / \
4   4
```

# Solution

The height of a tree is defined as the max depth of all child nodes. And to know if a tree is height-balanced, we need to compare the height of its left and right subtree, so we should have a function to get the height (max depth) of a given tree (root node).

We can let this function return a special value, e.g. `-1` as no tree's height can be negative value, to indicate the tree is height-unbalanced. Then whenever a tree's height is returned as `-1`, we can return all the way up to the root, because if any subtree is height-unbalanced, the whole tree is height-unbalanced (in other words the attribute of height-unbalanced is passed from any subtree to root node).

If both left and right subtrees are height-balanced, we need to check if current tree is balanced, by comparing left and right subtree's heights. If yes, then return the height of current tree, which is the larger one of left and right subtree's heights plus 1.

So in summary, there are 3 cases when a tree is height-unbalanced:

- Its left subtree is unbalanced.
- Its right subtree is unbalanced.
- The diff between its left and right subtree's heights are bigger than 1.
