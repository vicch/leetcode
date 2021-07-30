"""
At bit level the adding of 2 numbers can be considered as 2 parts:
- The in-place bit after the adding
- The carry-over bit

For the bit in-place, it follows these rules:
Bit A:  0  0  1  1
Bit B:  0  1  0  1
Result: 0  1  1  0 = A ^ B

For the carry-over bit:
Bit A: 0  0  1  1
Bit B: 0  1  0  1
Carry: 0  0  0  1 = A & B

With the carry-over bit being shifted 1 bit to the left, it can be used for the calc of next bit.
"""
class Solution(object):
    def getSum(self, a, b):
        """
        :type a: int
        :type b: int
        :rtype: int
        """
        carry = 0
        # Mask for overflow proctection
        mask = 0xffffffff

        # Continue until there are no more bits to carry over
        while b & mask != 0:
        	# Calc the bits to carry over to higher bits
            carry = (a & b) << 1
            # Calc in-place bits
            a = a ^ b
            # Swap carry-over bits to B
            b = carry

        # If there is still bits in B, it has overflown, only keep the parts of A inside mask
        return a & mask if b > mask else a
