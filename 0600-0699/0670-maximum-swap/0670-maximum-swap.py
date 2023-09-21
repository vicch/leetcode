"""
Consider the max possible number that can be made from the digits of given number, which must have all the digits in
descending order. If the current number is equal to this optimal value, then no swap is needed. If not, then the first
digit from the left that diverges from the optimal value is the digit to be swapped for max increase.

Based on the optimal value, we know what should be the value to be swapped to this digit, then we can find this target
value from the lower end, to minimize the decrease when swapping it to the higher end.

Time: O(nlogn) for the sorting
Space: O(n)
"""
class Solution(object):
    def maximumSwap(self, num):
        """
        :type num: int
        :rtype: int
        """
        digits = list(str(num))

        optimal = sorted(digits, reverse=True)

        # Find the optimal index to swap the digit to.
        i = 0
        while i < len(digits) and digits[i] == optimal[i]:
            i += 1
        if i == len(digits):
            return num
        
        # Find current index of the digit to swap.
        j = len(digits) - 1
        while digits[j] != optimal[i]:
            j -= 1
        
        digits[i], digits[j] = digits[j], digits[i]
        
        return int(''.join(digits))
