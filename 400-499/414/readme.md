# Problem

Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. The time complexity must be in O(n).

## Example 1

```
input  = [3, 2, 1]
output = 1
```

## Example 2

```
input  = [1, 2]
output = 2
```

## Example 3

```
input  = [2, 2, 3, 1]
output = 1

The third maximum here means the third maximum distinct number.
Both numbers with value 2 are both considered as second maximum.
```

# Solution

Use 3 variables to store the 1st, 2nd and 3rd maximum numbers. Pass the numbers down respectively if a new 1st, 2nd or 3rd maximum number is found.

There is an edge case in some languages where there is not an "empty" value for integer, e.g. `NULL` in C++ equals to `0`, if there is negative number in the sequence, the comparison will be invalid. So we need to set the init values of these variables to be `INT_MIN`.

Then comes the problem that it's possible the sequence actually has `INT_MIN`. So to distinguish `INT_MIN` from the init state of the variables, we store `number + 1` instead of `number` in the variables, and decrement the value in the variable by `1` before returning. (However, this will break if the sequence has `INT_MAX`, but appareantly the test cases don't have this edge case.)
