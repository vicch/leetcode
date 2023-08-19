# Problem

Given a 32-bit signed integer, reverse digits of an integer.

## Example 1

```
input  = 123
output = 321
```

## Example 2

```
input  = -123
output = -321
```

## Example 3

```
input  = 120
output = 21
```

## Note

Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−2^31, 2^31 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

# Solution

At any step, the right-most digit of input can be obtained by mod it with 10, then this digit should be appended as the right-mode digit of the output, while the existing digits are shifted to the left by multiply with 10. This goes on till the input becomes 0.

```
input  = 123
output = 0

input  = 12
output = 3

input  = 1
output = 32

input  = 0
output = 321
```

A simple way to avoid overflow during this process is to use a larger type (e.g. `long`) to contain the output value, and cast it into the smaller type (`int`) when returning.
