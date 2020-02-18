# Problem

Given a string, find the length of the longest substring without repeating characters.

## Example 1

```
input  = "abcabcbb"
output = 3

The answer is "abc", with the length of 3.
```

## Example 2

```
input  = "bbbbb"
output = 1

The answer is "b", with the length of 1.
```

# Solution

Manually walk through a sample string and observe how the answer is found.

```
abcabcbb

a     // Latest substring = a, longest substring length = 1
ab    // Latest substring = ab, longest substring length = 2
abc   // Latest substring = abc, longest substring length = 3
abca  // Latest substring = bca (the last "a" is removed), longest substring length = 3
abcab // Latest substring = cab (the last "b" is removed), longest substring length = 3
...
```

So for each position, there is a moving window which:

- starts from the position next to the last position of the current character, and
- ends on current position.

This window marks the longest non-repeating substring ending on this position. The length of the largest window among all positions is the answer we are looking for.

To get this window, we need to maintain a lookup list of each character's last occurrence position. So for each iteration of the string:

1. Update the window, by moving the starting position of the window to the next to the last occurrence of current character, and ending position to current position.
2. Maintain the longest non-repeating substring, by checking if current window's length is longer than the current longest non-repeating substring's length.
3. Update the lookup list, to refresh the last occurrence of current character.
