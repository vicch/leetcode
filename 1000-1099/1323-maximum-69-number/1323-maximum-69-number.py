"""
Straightforward string manipulation problem. The trick is handling type conversions and digit manipulation.

- Convert int → str to manipulate individual digits
- Use str.replace() with count=1 to change only the first '6' to '9'
- Convert str → int to return the result

Time complexity: O(d) where d is the number of digits
Space complexity: O(d) for the string representation
"""

class Solution(object):
    def maximum69Number(self, num):
        """
        :type num: int
        :rtype: int
        """
        return int(str(num).replace('6', '9', 1))
