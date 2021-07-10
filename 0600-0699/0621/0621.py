from collections import Counter

class Solution(object):
	def leastInterval(self, tasks, n):
		"""
		:type tasks: List[str]
		:type n: int
		:rtype: int
		"""
		totalRemain = len(tasks.len)
		tasksRemain = sorted([v for k, v in Counter(tasks).items()], reverse=True)
		tasksCount = len(tasksRemain)

		slot = -1
		lastSlots = []

		while totalRemain > 0:
			for i in range(tasksCount):
				
		
