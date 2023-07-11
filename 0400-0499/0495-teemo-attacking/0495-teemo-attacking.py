class Solution(object):
    def findPoisonedDuration(self, timeSeries, duration):
        """
        :type timeSeries: List[int]
        :type duration: int
        :rtype: int
        """
        count = len(timeSeries)

        # First assuming no attack was reset
        total = count * duration

        # For each attack, minus the overlapping duration with the next attack
        for i in range(count - 1):
            overlap = timeSeries[i] + duration - timeSeries[i + 1]
            if overlap > 0:
                total -= overlap

        return total
