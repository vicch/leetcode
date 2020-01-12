# Problem

Given an array of characters, compress it in-place.

Every element of the array should be a character (not int) of length 1.

After you are done modifying the input array in-place, return the new length of the array.

The length after compression must always be smaller than or equal to the original array. Which means the minimum number of repeated chars that should be compressed is 2. In other words, `["a", "a"]` should be compressed as `["a", "2"]`, while `["a", "b"]` shouldn't be compressed (or should be compressed as is).

Try to solve it using only `O(1)` extra space only.

## Example 1

```
input  = ["a","a","b","b","c","c","c"]
output = 6
array  = ["a","2","b","2","c","3"]
```

## Example 2

```
input  = ["a"]
output = 1
array  = ["a"]
```

## Example 3

```
input  = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
output = 4
array  = ["a","b","1","2"]

"bbbbbbbbbbbb" is replaced by "b12". Each digit has its own entry in the array.
```

## Note

- All characters have an ASCII value in `[35, 126]`.
- `1 <= len(chars) <= 1000`.

# Solution

The solution with `O(1)` space is to use multiple pointers:

- A fast running pointer that marks the end of the current consecutive sequence of the same char.
- A slow running pointer that marks the start of the current current consecutive sequence of the same char.
- A pointer that marks the writing positiong of the compressed array.

For example:

```
a a a b b b c c // Original array
      ^     ^
      |     |
      |     +- Fast pointer keeps moving till a different char is found
      +------- Slow pointer marks the start of the repeating part "b b b"
    +--------- Current writing position, next char to write is "b"
    |
    v
a 3 ? ? ? ? ? ? // Compressed array
```

Be careful that the movement of the last pointer is tricky.
