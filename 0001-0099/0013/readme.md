# Problem

Roman numerals are represented by 7 different symbols:

```
Symbol  Value
I       1
V       5
X       10
L       50
C       100
D       500
M       1000
```

For example:

- 2 is written as `II` in Roman numeral, just two 1s added together.
- 12 is written as, `XII`, which is simply `X` + `II`.
- 27 is written as `XXVII`, which is `XX` + `V`+ `II`.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for 4 is not `IIII`. Instead, it is written as `IV`. Because the 1 is before the 5, we subtract it making 4. The same principle applies to the number 9, which is written as `IX`. There are 6 instances where subtraction is used:

- `I` can be placed before `V` (5) and `X` (10) to make 4 and 9.
- `X` can be placed before `L` (50) and `C` (100) to make 40 and 90.
- `C` can be placed before `D` (500) and `M` (1000) to make 400 and 900.

Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.

## Example 1

```
input  = "III"
output = 3
```

## Example 2

```
input  = "IX"
output = 9
```

## Example 3

```
input  = "MCMXCIV"
output = 1994
```

# Solution

If there is no special rule for substraction, the number can be obtained by adding up the values represented by each letter.

With that rule, for each letter's value `A`, we need to lookahead of the value `B` of the ext letter, and

- If `A >= B`, it's not subtraction, `A` should be added to the total value.
- If `A < B`, it's substraction, `A` should be subtracted from the total value.

Then on the next iteration, value `B` becomes the new value `A`, so that we don't waste the parsing of `B`.
