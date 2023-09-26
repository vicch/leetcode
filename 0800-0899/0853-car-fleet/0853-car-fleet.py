"""
When a car X catches up with the car Y before it, they basically merge into one car that continues to run with the
speed of Y. Cars following X will merge into the same fleet if it can catch up with Y before the target.

So we only need to iteratively check if each car can catch up with the leadning car of the fleet before it:
- If it can, then it will merge into the fleet at some point, which we don't care about, and can continue.
- If not, then it starts a new fleet.

Time: O(n)
Space: O(1)
"""
class Solution(object):
    def carFleet(self, target, position, speed):
        """
        :type target: int
        :type position: List[int]
        :type speed: List[int]
        :rtype: int
        """
        cars = sorted(zip(position, speed), key=lambda x: x[0], reverse=True)

        # First car leads the first fleet.
        fleets = 1
        lead, leadFinishTime = 0, 1.0 * (target - cars[0][0]) / cars[0][1]

        for i in range(1, len(cars)):
            # Current car leads a new fleet if:
            # - It is slower than the leading car of closest fleet, or
            # - It is faster, but it cannot catch up before the leading car finishes
            if cars[i][1] <= cars[lead][1] or 1.0 * (cars[lead][0] - cars[i][0]) / (cars[i][1] - cars[lead][1]) > leadFinishTime:
                # Update the latest fleet.
                fleets += 1
                lead, leadFinishTime = i, 1.0 * (target - cars[i][0]) / cars[i][1]

        return fleets
