# Problem

Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

## Example 1

```
input  = 121
output = true
```

## Example 2

```
input  = -121
output = false

From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
```

## Example 3

```
input  = 10
output = false

10 reads 01 from right to left. Therefore it is not a palindrome.
```

# Solution

Basically the problem is checking if a number equals to its corresponding number with all digits reversed. If so, then it's a palindrome.

Reversing the digits of a number is covered in problem #7.

Some special cases:

- According to the definition, all negative numbers are not palindromes.
- According to the definition, all numbers ending with `0` (except `0` itself) are not palindromes.
- All single digit positive numbers are palindromes.
