"""
Straightforward traversal of the coordinates, by checking if it's valid, and compute its distance if valid, and
maintain a global optimal result of the index and min distance.
"""
class Solution(object):
    def nearestValidPoint(self, x, y, points):
        """
        :type x: int
        :type y: int
        :type points: List[List[int]]
        :rtype: int
        """
        def isValid(point):
            return point[0] == x or point[1] == y
        
        def getDistance(point):
            return abs(point[0] - x) + abs(point[1] - y)
        
        index = -1
        minDistance = float('inf')

        for i, point in enumerate(points):
            if not isValid(point):
                continue
            distance = getDistance(point)
            if distance < minDistance:
                minDistance = distance
                index = i
        
        return index
