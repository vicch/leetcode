# Problem

You are climbing a stair case. It takes `n` steps to reach to the top. Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

## Example

```
input  = 3
output = 3

1. 1 step + 1 step + 1 step
2. 1 step + 2 step
3. 2 step + 1 step
```

# Solution

Define `f(n) = number of ways to climb n steps`. It's clear to see that `f(n) = f(n-1) + f(n-2)`, which is actually the transition function between numbers in the Fibonacci sequence. So the problem can be changed to: get the nth item in the Fibonacci sequence:

```
item #     0, 1, 2, 3, 4, 5, ...
item value 1, 1, 2, 3, 5, 8, ...
```

Because at any item `x` we only care about the last 2 items `x-1` and `x-2`, we can use 2 variables to represent them and to calculate item `x`, and in the next iteration, they contain the values of item `x-1` and `x`, to calculate item `x+1`.
