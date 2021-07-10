# Problem

Given an integer, write an algorithm to convert it to hexadecimal. For negative integer, two’s complement method is used.

## Example 1

```
input  = 26
output = "1a"
```

## Example 2

```
input  = -1
output = "ffffffff"
```

## Note

1. All letters in hexadecimal `a-f` must be in lowercase.
2. The hexadecimal string must not contain extra leading `0`. If the number is zero, it is represented by a single zero character `0`; otherwise, the first character in the hexadecimal string will not be the zero character.
3. The given number is guaranteed to fit within the range of a 32-bit signed integer.
4. You must not use any method provided by the library which converts/formats the number to hex directly.

# Solution

A simple solution is to take advantage of the native presentation of integers in the system and binary calculations. By doing `n & 0xf`, the last 4 binary digits of `n` is captured, and the value can be mapped to a hex char.

But this solution is limited to hexademical. A more generalized solution should support converting a decimal number to a N-base string (N is 16 in the case of this problem).

By using the general method of converting decimal to N-base number, we mod the number by N and keep the reminder, then divide by N and continue to the next digit. The result is a backward sequence of numbers indicating the digits, e.g. `{10, 1, 0, 0, ...}` translates to hexadecimal `1a`.

Then we iterate the sequence reversely (discard the trailing `0` first) and translate each digit to a char.
