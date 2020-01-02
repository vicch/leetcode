# Problem

Given an array of integers that is already sorted in **ascending order**, find two numbers such that they add up to a specific target number.

The function should return indices of the two numbers such that they add up to the target, where the first index must be less than second index. The indices should be 1-based, not 0-based.

## Example

```
numbers = [2,7,11,15]
target  = 9
result  = [1,2]
```

## Note

You may assume that each input would have exactly one solution and you may not use the same element twice.

# Solution

Use a hash table to store indices of the numbers, while iterating the list. For each number `x`, check if `target - x` is already in the hash table. If so, return the 2 indice.
