"""
The carrying to higher digit continues as long as the current digit is 9, so we need to find the first digit that isn't
9 from the lowest digit backwards while setting all digits to 0, stop at the first digit that isn't 9 and increment it
by 1.

If the pointer is past index 0, then all digits were 9, prepend a digit 1 in this case.

Time: O(n), n = number of digits
Space: O(n) in worst case, where a new list of n digits is allocated
"""
class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        i = len(digits) - 1
        while i >= 0 and digits[i] == 9:
            digits[i] = 0
            i -= 1
        
        if i == -1:
            digits = [1] + digits
        else:
            digits[i] += 1

        return digits
