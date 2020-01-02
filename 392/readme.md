# Problem

Given a string `s` and a string `t`, check if `s` is subsequence of `t`.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. E.g. `ace` is a subsequence of `abcde`, while `aec` is not.

## Example 1

```
s = "abc"
t = "ahbgdc"
result = true
```

## Example 2

```
s = "axc"
t = "ahbgdc"
result = false
```

## Note

- You may assume that there is only lower case English letters in both `s` and `t`.
- `t` is potentially a very long (length ~= 500,000) string, and `s` is a short string (<=100).

# Solution

The problem is actually checking if the chars of `s` show up in the same order in `t`, regardless of their actual positions in `t`. So we can iterate the chars of `s` and `t`, always move forward on `t`, but only move forward on `s` when the current char is found.
