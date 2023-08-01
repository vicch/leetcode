"""
One of the most stupid questions. Perhaps the only trick is to keep 2 running counters and reset them every 3 and 5
iterations, which is slightly faster than dividing the numbers.
"""
class Solution(object):
    def fizzBuzz(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        res = []

        fizz, buzz = 0, 0
        for i in range(1, n+1):
            fizz += 1
            buzz += 1
            word = ""

            if fizz == 3:
                word += "Fizz"
                fizz = 0
            if buzz == 5:
                word += "Buzz"
                buzz = 0
            if len(word) == 0:
                word = str(i)

            res.append(word)

        return res
