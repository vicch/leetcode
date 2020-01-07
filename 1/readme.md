# Problem

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

## Example

```
numbers = [2, 7, 11, 15]
target  = 9
output  = [0, 1]
```

# Solution

## With Hash Map

Inserting all numbers into the map, with number values as keys and indices as values. Then for each number, look in the map for the corresponding number that will make the target sum. If found, return the indice.

Assuming the map values default to `0`, to distinguish the default value from the index `0`, instead of inserting `index` value to the map, insert `index + 1`, and when returning, offset that by doing a `map[x] - 1`.

## Without Hash Map

Iterating all combinations of 2 numbers, and return the indices when the target sum is met.
