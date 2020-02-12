# Problem

The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers `x` and `y`, calculate the Hamming distance.

## Example

```
x = 1
y = 4
output = 2

1 (0 0 0 1)
4 (0 1 0 0)
     ↑   ↑
```

## Note

`0 =< x, y < 2^31`

# Solution

XOR operation can differenciate digits that are same or different. The number of `1`s in the result of `x XOR y` is the Hamming distance between `x` and `y`.
