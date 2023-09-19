"""
As we are constantly moving the window by inserting elements on one end and removing on the other, it's natural to use
a queue based on double-linked list to store the values. Also keep a running sum of the elements in queue, and increase
or decrease it accordingly.

Time: O(1)
Space: O(n)
"""
class MovingAverage(object):

    def __init__(self, size):
        """
        :type size: int
        """
        self.size = size
        self.window = collections.deque([])
        self.sum = 0

    def next(self, val):
        """
        :type val: int
        :rtype: float
        """
        self.window.append(val)
        self.sum += val

        # Remove one element from front if size is exceeded. As we do this for each next value, there should be at most
        # one element to remove.
        if len(self.window) > self.size:
            self.sum -= self.window.popleft()
        
        # Divide as floating point values.
        return 1.0 * self.sum / len(self.window)
