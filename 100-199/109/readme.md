# Problem

Given a singly linked list where elements are sorted in ascending order, convert it to a height-balanced BST.

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

## Naive

The problem with linked list is that we don't have O(1) random access to the elements, so it's hard to create the BST in a top-down approach like problem #108.

A naive solution is to first convert the linked list to an array, then reuse problem #108's solution.

## Inorder Traversal

The sorted linked list can be considered as an inorder traversal of the expected BST. So we can build the BST as if we are inorder traversing the BST.

We can use the returning phase of the recursive call stack to achieve a bottom-up process, then by maintaining (move the pointer as if doing an inorder traversal) an external pointer to the corresponding element in the linked list, and assign the element's value to the current tree node.
