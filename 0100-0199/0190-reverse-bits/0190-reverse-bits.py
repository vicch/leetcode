"""
To reverse the bits, take bits from lower end of input while right shifting, then push the bits to lower end of the
reversed number while left shifting.

Follow up: If this function is called many times, how would you optimize it?

We can trade space for time, by pre-computing a lookup array for chunks of N bits and their respective reversed version.

cache = [reverse(i) for i in range(256)]
def reverse(n):
    reversed = 0
    for _ in range(8):
        reversed = (reversed << 1) | (n & 1)
        n >>= 1
    return reversed

Then instead of moving 1 bit per loop, move 8 bits in one go by looking up the result.
"""
class Solution:
    # @param n, an integer
    # @return an integer
    def reverseBits(self, n):
        rev = 0
        for _ in range(32):
            rev <<= 1
            rev |= n & 1
            n >>= 1
        return rev
