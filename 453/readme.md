# Problem

Given a non-empty integer array of size `n`, find the minimum number of moves required to make all array elements equal, where a move is incrementing `n - 1` elements by 1.

## Example

```
input  = [1,2,3]
output = 3

[1,2,3] => [2,3,3] => [3,4,3] => [4,4,4]
```

# Solution

Incrementing `n - 1` elements by 1 has the same effect to the relative differences among the numbers as decrementing 1 element by 1. So the problem is equivalent to how many moves are needed to decrement all numbers to be equal to the minimum number in the array, where a move is decrementing 1 element by 1.
