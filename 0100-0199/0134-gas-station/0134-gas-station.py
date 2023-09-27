"""
Firstly if there is a solution, then sum(cost) >= sum(gas).

Secondly we can assume each station is the solution while iterating the stations. A station cannot be the solution if
remaing gas at this station is below 0. In such case, we can exclude it and continue to assume the next station being
the solution. Because there is only one answer, the station that isn't excluded at the end must be the answer (assuming
there is a solution).

Time: O(n)
Space: O(1)
"""
class Solution(object):
    def canCompleteCircuit(self, gas, cost):
        """
        :type gas: List[int]
        :type cost: List[int]
        :rtype: int
        """
        overallRemain, curRemain = 0, 0
        result = 0

        for i in range(len(gas)):
            gain = gas[i] - cost[i]
            overallRemain += gain
            curRemain += gain

            if curRemain < 0:
                curRemain = 0
                result = i + 1
        
        return result if overallRemain >= 0 else -1
