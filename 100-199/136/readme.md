# Problem

Given a non-empty array of integers, every element appears twice except for one. Find that single one.

## Example 1

```
input  = [2,2,1]
output = 1
```

## Example 2

```
input  = [4,1,2,1,2]
output = 4
```

# Solution

The XOR calculation has these properties:

```
x XOR 0 = x
x XOR x = 0
x XOR y XOR x = (x XOR x) XOR y = 0 XOR y = y
```

So if all numbers are connected by XOR together, the final result will be the single number.
