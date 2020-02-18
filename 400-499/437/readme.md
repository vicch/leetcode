# Problem

You are given a binary tree in which each node contains an integer value. Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

## Example

```
root   = [10,5,-3,3,2,null,11,3,-2,null,1]
sum    = 8
output = 3

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

5 -> 3
5 -> 2 -> 1
-3 -> 11
```

## Note

The tree has no more than 1,000 nodes, and the values are in the range -1,000,000 to 1,000,000.

# Solution

## Simple DFS

For any node in the tree, all the paths that filfull the requirement can be categorized as:

- Paths that start from current node
- Paths that start from a descendent node of current node

To count the second category of paths, we can call the base method recursively on the child nodes of current node, and the results up.

To count the first category of paths, we need to add up all the values of nodes starting from current node, and ending on any descendent node of current node. Whenever the sum of these nodes equals to the target, one path is found.

## Hash Map and DFS

The simple DFS involves repeated calculations on the same flow between 2 nodes. E.g. for route `1->3->5`, DFS will calculate `1, 1 + 3, 1 + 3 + 5, 3, 3 + 5, 5`. This can be optimized by reducing repeated calculations. Here is how it works:

Consider a DFS route from root to the current node, e.g. `t1->t2->...->tn`.

Firstly, we track the sum of `t1` to `tn`, by passing the value down the DFS recursive calls, and increment it with value of every node along the way. We call this value `total`:

```
total = t1 + t2 + ... + tn
```

Then, we use a hash map `cache` to cache how many times different sum values have been reached from `t1` to `tn`, so:

```
cache[t1]           += 1
cache[t1 + t2]      += 1
cache[t1 + t2 + t3] += 1
...
```

Because there are negative numbers in the tree, the same value may be reached multiple times on the route `t1->t2->...->tn`.

Now we check if the value `cache[total - target]` exists, because if it exists, it means:

```
total - target = t1 + t2 + ... + tm (m <= n)
// Because we already know
total = t1 + t2 + ... + tn
// So we know
target = tm+1 + tm+2 + ... + tn
```

In other words, route `tm+1->tm+2->...->tn` is a path that we are looking for. So we can add `cache[total - target]` to the total number of paths.

Then we continue the DFS to the child nodes of current node.

But note that after the DFS on node `tn`, we need to decrement `cache[total]`, because now we have tried all possible paths under `tn`.
