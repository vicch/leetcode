# Problem

Given a binary array, find the maximum number of consecutive `1` in this array.

## Example

```
input  = [1,1,0,1,1,1]
output = 3
```

## Note

- The input array will only contain `0` and `1`.
- The length of input array is a positive integer and will not exceed 10,000.

# Solution

Iterate the array and maintain 2 counters:

- one counter gets incremented for each consecutive `1`
- one counter contains the length of the longest consecutive `1` so far

When a `0` is met, reset the first counter to 0, and see if the second counter needs update.
