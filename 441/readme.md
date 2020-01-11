# Problem

You have a total of `n` coins that you want to form in a staircase shape, where every `k`-th row must have exactly `k` coins.

Given `n`, find the total number of full staircase rows that can be formed.

## Example 1

```
input  = 5
output = 2

The coins can form the following rows:
¤
¤ ¤
¤ ¤
Because the 3rd row is incomplete, we return 2.
```

## Example 2

```
input  = 8
output = 3

The coins can form the following rows:
¤
¤ ¤
¤ ¤ ¤
¤ ¤
Because the 4th row is incomplete, we return 3.
```

## Note

`n` is a non-negative integer and fits within the range of a 32-bit signed integer.

# Solution

## Brute Force

Assuming the result is `m`, then we must have:

```
m * (m + 1) / 2 <= n < (m + 1) * (m + 2) / 2
```

So we can iterate `x` from 1 up till `x * (x + 1) > n`, then `x - 1` will be the answer `m`.

## Range Analysis

Assuming the result is `m`, consider these values:

```
A = m * (m + 1) = m ^ 2 + m
B = (m + 1) ^ 2 = m ^ 2 + 2m + 1
C = (m + 1) * (m + 2) = m ^ 2 + 3m + 2

It's clear that A < B < C
```

As mentioned in the brute force solution, we must have:

```
A <= 2n < C
```

Depending on the relation between `2n` and `B`, there can be 2 cases:

```
If A <= 2n < B, then floor(sqrt(2n)) == m
If B <= 2n < C, then floor(sqrt(2n)) == m + 1
```

Now we only need to check if the result is `m` or `m + 1`, by validating it against the first equation.
