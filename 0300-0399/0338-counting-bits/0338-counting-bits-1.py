"""
Problem:
Given a non negative integer number num. For every numbers i in the range
0 ≤ i ≤ num calculate the number of 1's in their binary representation and
return them as an array. Example: For num = 5 should return [0,1,1,2,1,2].

Solution:
The numbers of 1's form a recursive sequence:
0
1(0+1)
1(0+1), 2(1+1)
1(0+1), 2(1+1), 2(1+1), 3(2+1)
...
Use 2 cursors:
- i runs from head to tail, setting value as s[j] + 1
- j runs from head to middle (of full 2^n sequence), and returns to head to
start again

Improvement:
j is actually i&(i-1)
"""

class Solution(object):
    def countBits(self, num):
        """
        :type num: int
        :rtype: List[int]
        """
        list = [0]
        for i in range(1, num + 1):
            list += [list[i & (i-1)] + 1]
        return list
