"""
This is essentially a math problem. Consider the 4 vertices of a square:

- When the first one (x1, y1) is given, the second one is either on its same X-axis or Y-axis, we take X-axis for example.
- When the second one (x1, y2) is chosen, the third one has only 2 possible choices: on the first's vertex's Y-axis, and with the same distance
  between the first 2 vertices.
- When the third one (x2, y1) is chosen, the fourth one (x2, y2) is unique identified.

So the process is basically we iterate all possible positions of the second vertex, then check the existence of the third and fourth.

For the lookup we need a nested dict keyed by the Xs and Ys, and value is the occurrence of that coord in the input.
"""
class DetectSquares(object):

    def __init__(self):
        self.xToY = defaultdict(lambda: defaultdict(int))
        

    def add(self, point):
        """
        :type point: List[int]
        :rtype: None
        """
        x, y = point
        self.xToY[x][y] += 1


    def count(self, point):
        """
        :type point: List[int]
        :rtype: int
        """
        x1, y1 = point
        solution = 0

        # Iterate candidates of second vertex
        for y2 in self.xToY[x1].keys():
            if y2 == y1:
                continue

            edge = y1 - y2
            
            # Third vertex option 1
            x2 = x1 + edge
            # Solution equals to the product of the occurrences of the 3 vertices.
            solution += self.xToY[x1][y2] * self.xToY[x2][y1] * self.xToY[x2][y2]

            # Third vertex option 2
            x2 = x1 - edge
            solution += self.xToY[x1][y2] * self.xToY[x2][y1] * self.xToY[x2][y2]
        
        return solution
