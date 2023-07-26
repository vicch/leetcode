"""
It's essentially getting all divisors of given number. Pay attention to boundary and condition:
- Iterate potential divisor between 2 and floor(sqrt(num))
- If sum of divisors has already exceeded, quit early.
"""
class Solution(object):
    def checkPerfectNumber(self, num):
        """
        :type num: int
        :rtype: bool
        """
        if num == 1:
            return False

        sum = 1
        for i in range(2, int(math.sqrt(num)) + 1):
            if num % i == 0:
                sum += i + num / i
            if sum > num:
                return False
        
        return sum == num
