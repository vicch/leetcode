# Problem

Given an integer array `nums`, find the contiguous subarray within an array (containing at least one number) which has the largest product.

## Example 1

```
input  = [2,3,-2,4]
output = 6

[2,3] has the largest product 6.
```

## Example 2

```
input  = [-2,0,-1]
output = 0

[0] has the largest product 0.
```

# Solution

Similar to problem #53, we have:

```
f(k) = max sum of all subarrays ending on element k
f(k + 1) = max(f(k) * nums[k], nums[k])
max product = max(f(0), f(1), ... f(n))
```

But with the presence of negative numbers, the product is different from sum in the sense that it may switch between positive and negative numbers, so the local smallest product has the potential of becoming the largest when being multiplied with a negative number.

So besides calculating the local max product, we also need to calculate the local min product.
