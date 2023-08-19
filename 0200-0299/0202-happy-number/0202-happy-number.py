"""
Any unhappy number will end up in a cycle. To detect the cycle, use a visited hash table to record the numbers that
have been from previous steps. If a number has been seen, it's unhappy.

Time: O(logn), because the number of digits in a number n is logn
Space: O(logn), for each step, a value is cached, and each value is O(1) space, e.g. int size
"""
class Solution(object):
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        def getNext(n):
            next = 0
            while n > 0:
                next += (n % 10) ** 2
                n /= 10
            return next

        cache = set()

        while n != 1 and n not in cache:
            cache.add(n)
            n = getNext(n)
        
        return n == 1
