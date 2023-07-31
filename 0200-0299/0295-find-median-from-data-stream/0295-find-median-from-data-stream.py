"""
To efficiently get the top/bottom K elements from a constantly changing list of values, it usually involves heap. The
median value in this case can be smartly achieve by using 2 heaps, which stores the smaller and larger half of the
values. The top of the max heap for the smaller half, or the top of the min heap for the larger half is the median.

The heaps need to be balanced after each insertion, to make sure the median is still at the top.

Note that Python's heapq is a min heap, to implement a max heap, negate the values before pushing and after poping.
"""
class MedianFinder(object):

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.left, self.right = [], []

    def addNum(self, num):
        """
        :type num: int
        :rtype: None
        """
        # Push to left or right.
        if len(self.left) == 0 or num < -1 * self.left[0]:
            heapq.heappush(self.left, -1 * num)
        else:
            heapq.heappush(self.right, num)

        # Re-balance after pushing
        if len(self.left) > len(self.right) + 1:
            heapq.heappush(self.right, -1 * heapq.heappop(self.left))
        elif len(self.left) < len(self.right):
            heapq.heappush(self.left, -1 * heapq.heappop(self.right))

    def findMedian(self):
        """
        :rtype: float
        """
        # For an even number of values, median is the average of the 2 top values.
        if len(self.left) == len(self.right):
            return (self.right[0] - self.left[0]) / 2.0
        else:
            return -1 * self.left[0]
