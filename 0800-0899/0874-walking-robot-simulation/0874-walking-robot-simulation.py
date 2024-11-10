"""
Basically maintain internal state of facing and current location of the robot, and mutate according to commands.

The current distance can be obtained after executing each command, and a global optimal value is maintained by comparing with it. It can be
proven that a global max distance must be achieved at the end of executing a command, instead of in the middle of it.
"""
class Robot(object):
    _DELTAS = [[0, 1], [1, 0], [0, -1], [-1, 0]]

    def __init__(self, obstacles):
        self.facing = 0
        self.x, self.y = 0, 0
        self.obstacles = {tuple(ob) for ob in obstacles}
    
    def turn(self, direction):
        if direction == -1:
            self.facing += 1
        elif direction == -2:
            self.facing -= 1
        # Handle out-of-bound value.
        self.facing %= 4
    
    def move(self, steps):
        dx, dy = self._DELTAS[self.facing]
        for i in range(steps):
            x, y = self.x + dx, self.y + dy
            # Stop moving whenever an obstacle is met.
            if (x, y) in self.obstacles:
                break
            self.x, self.y = x, y
    
    def distance(self):
        return self.x ** 2 + self.y ** 2

class Solution(object):
    def robotSim(self, commands, obstacles):
        """
        :type commands: List[int]
        :type obstacles: List[List[int]]
        :rtype: int
        """
        robot = Robot(obstacles)
        maxDist = 0

        for command in commands:
            if command < 0:
                robot.turn(command)
            else:
                robot.move(command)
            maxDist = max(maxDist, robot.distance())
        
        return maxDist
