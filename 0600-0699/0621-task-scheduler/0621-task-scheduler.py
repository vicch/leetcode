"""
The basic strategy to minimize the total time is to always prioritize scheduling the task with max remaining count for each slot, while
respecting the min interval.

So the scheduled tasks can be considered as split into windows with size of n+1, and for each window, we schedule the remaining tasks sorted by
remaining counts in descending order.

As we need to repeatedly fetch and save top K elements, it's natural to use heap to store the remaining tasks and counts.

The trick is the conditional flow and counters maintenance for each cycle.

Time complexity:
- O(NlogK), if heap operation is O(logK), or K can be considered constant as it's max 26.

Space complexity:
- O(K), same as above, can be considered O(1) because K is constant.
"""
class Solution(object):
    def leastInterval(self, tasks, n):
        """
        :type tasks: List[str]
        :type n: int
        :rtype: int
        """
        counts = Counter(tasks)
		# Init max heap with negative counts
        heap = [[-c[1], c[0]] for c in counts.items()]
        heapq.heapify(heap)

        timer = 0
        while heap:
			# Slots to fill for each cycle by respecting the interval
            slots = n + 1
			# Number of scheduled tasks for this cycle
            scheduled = 0
			# Temp list of remaining tasks to be pushed back to the heap after this cycle
            remaining = []

            while slots > 0 and heap:
				# Schedule task with currently max count
                task = heapq.heappop(heap)

				# Task needs to be pushed back if it has remaining count after this cycle
                if task[0] < -1:
                    remaining.append([task[0] + 1, task[1]])

                scheduled += 1
                slots -= 1
            
            # Push remaining tasks back
            for task in remaining:
                heapq.heappush(heap, task)
            
			# If there is remaining task, there will be next cycle, and current cycle is filled up with idle slots.
			# Otherwise, this is the last cycle and there is no trailing idle slot.
            timer += n + 1 if heap else scheduled
        
        return timer
