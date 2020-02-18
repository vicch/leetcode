# Problem

Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.

## Example

```
input  = "Hello, my name is John"
output = 5
```

## Note

- The string does not contain any non-printable characters.

# Solution

Generally the problem is about counting the state changes while iterating the string of either

- Changing from non-space to space, or
- Changing from space to non-space.

Special situtions to consider:

- Possible consecutive spaces at the beginning or end of the string, and
- Possible consecutive spaces in the middle of the string.

## Solution 1

Count the state change from space to non-space, and increment the count for each change. But for the first char of the string, increment the count as long as it's non-space.

## Solution 2

Append a space to the end of the string, and count the state change from non-space to space. No special case needs to be considered.
