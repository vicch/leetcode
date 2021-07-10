# Problem

Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.

## Example 1

```
input  = abab
output = true

"abab" is "ab" repeating twice.
```

## Example 2

```
input  = aba
output = false
```

## Example 3

```
input  = abcabcabcabc
output = true

"abcabcabcabc" is "abc" repeating 4 times, or "abcabc" repeating twice.
```

## Note

You may assume the given string consists of lowercase English letters only, and its length will not exceed 10000.

# Solution

Though it seems to be a string problem, it's actually a number theory problem.

If string `A` is a substring `A'` repeating `n` times, and length of `A'` is `m`, then length of `A` is `n * m`.

So for a string, assuming its length is `l`, we can check for each factor `n` of `l`, if the `n` substrings of it are identical:

- If we find such a `n`, then return `true`.
- If all factors of `l` don't fulfill the requirement, then return `false`.

We only need to check the prime factors, because e.g. if the string can be devided into 4 identical substrings, then it also can be divided into 2 identical substrings. In other words, if the string can't be devided into 2 substrings, then it can't be divided into 4 substrings. So in this case, we only need to check the prime factor 2, and skip all factors that are multiples of 2.
