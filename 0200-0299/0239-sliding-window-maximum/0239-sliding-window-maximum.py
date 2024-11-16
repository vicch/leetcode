"""
The problem is essentially getting the top 1 value from a list that is constantly updated, so naturally heap can be used to store the numbers
in the window, while the top is the max value.

The tricky part is how to pop numbers that are out of the window from the heap. The solution is lazy popping: when we peek the top element,
check if it's within the window, if not, it can be popped, and repeat until the top is an element within the window.

This can be achieved by storing both the number and its index in the original list.

Time complexity:
- O(NlogK), because each number is pushed and popped at most once from the heap, which has O(logK) complexity.

Space complexity:
- O(N), because the heap is O(K) and the result list is O(N - K).
"""
class Solution(object):
    def maxSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        heap = []

        # Populate first K-1 numbers.
        for i in range(k-1):
            heapq.heappush(heap, (-nums[i], i))
        
        max = []
        for i in range(k-1, len(nums)):
            # For each cycle, first push the current number.
            heapq.heappush(heap, (-nums[i], i))
            # Then pop until a number within the window is at the top.
            while heap[0][1] <= i-k:
                heapq.heappop(heap)
            # Number at the top is the max within window.
            max.append(-heap[0][0])
        
        return max
