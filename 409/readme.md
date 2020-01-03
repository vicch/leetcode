# Problem

Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example `Aa` is not considered a palindrome here.

## Example

```
input  = "abccccdd"
output = 7

One longest palindrome that can be built is "dccaccd", whose length is 7.
```

## Note

- Assume the length of given string will not exceed 1010.

# Solution

We just need to count how many pairs of identical chars are in the string. After taking out all the pairs, if there is still char left, take one of them to be the center of the palindrome.
