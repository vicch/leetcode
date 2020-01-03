# Problem

Write a program that outputs the string representation of numbers from 1 to n.

But for multiples of 3 it should output `Fizz` instead of the number, and for the multiples of 5 output `Buzz`. For numbers which are multiples of both 3 and 5 output `FizzBuzz`.

## Example

```
n = 15
result = ["1", "2", "Fizz", "4", "Buzz", "Fizz", "7", "8", "Fizz", "Buzz", "11", "Fizz", "13", "14", "FizzBuzz"]
```

# Solution

Just iterate from 1 to n and check for multiples of 3 and 5. Presumably using counters that reset every 3 or 5 loops is faster than doing mods.
