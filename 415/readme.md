# Problem

Given two non-negative integers `num1` and `num2` represented as strings, return the sum of them.

## Note

- The length of both `num1` and `num2` is < 5100.
- Both `num1` and `num2` contains only digits `0-9`.
- Both `num1` and `num2` don't contain any leading zero.
- You must not use any built-in BigInteger library or convert the inputs to integer directly.

# Solution

Iterate from the last to first digit on both numbers, and add each pair of digits up to get the digits of the sum. Carry over value is passed on to the next digit.

The result of this operation is a sequence of digits, but it's in reverse order. Reverse the digits to get the result string.
