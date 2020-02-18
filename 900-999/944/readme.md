# Problem

(The original problem description is pretty lame. Here is an improved version.)

The input is an array `A` of `N` lowercase letter strings, all of the same length. If these strings are written one per row, they will form a matrix, e.g. `["cba","daf","ghi"]` will become

```
cba
daf
ghi
```

In this matrix, each column is a sequence of characters. A sequence is called non-decreasing if any 2 adjacent characters are not in a decreasing order. E.g. `cdg` or `aaa` are non-decreasing sequences, while `bah` is not a non-decreasing sequence.

The function should return the number of columns in the matrix that are not non-decreasing. In other words, `return_value = total_columns - non_decreasing_columns`.

# Solution

Simply iterate through the columns, and maintain a counter. Increment the counter and continue to next column if any decreasing pair is found in a column.