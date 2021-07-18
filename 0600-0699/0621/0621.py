from collections import Counter

class Solution(object):
	def leastInterval(self, tasks, n):
		"""
		:type tasks: List[str]
		:type n: int
		:rtype: int
		"""

		# Remaining number of all tasks
		remain = len(tasks)

		# Count the occurrence of each task
		# E.g. [A, A, B, B, B, C, C] -> [2, 3, 2]
		counts = [v for k, v in Counter(tasks).items()]

		counters = self.getCounters(counts)

		# The last unit that each task was scheduled
		lastUnits = [None] * len(counts)

		unit = 0
		# If current unit has scheduled a task
		scheduled = False

		# Continue till no task remains
		while remain > 0:
			unit += 1
			scheduled = False

			# Iterate the counters list backwards, i.e. from the tasks with the max remaining numbers to 1
			for i in range(len(counters) - 1, 0, -1):

				# If no tasks with remaining number x, skip
				if not counters[i]:
					continue

				# Iterate the tasks
				for j in range(len(counters[i])):
					task = counters[i][j]
					
					# If the task hasn't been scheduled (its last unit is empty), or if the interval between its last
					# unit and current unit is big enough, schedule the task in current unit
					if lastUnits[task] is None or unit - lastUnits[task] > n:
						# Move the task index from current counter to the counter minus 1, because this task has 1 less
						# remaining number now
						counters[i].pop(j)
						counters[i - 1].append(task)

						remain -= 1
						lastUnits[task] = unit
						scheduled = True
				
					# If a task is scheduled, skip remaining tasks
					if scheduled:
						break
			
				# If a task is scheduled, skip remaining tasks
				if scheduled:
					break

		return unit

	def getCounters(self, counts):
		"""
		:type counts: List[int]
		:rtype: List[List[int]]
		"""

		# Counter of tasks, keys are the task's remaining number, values are list of task indexes
		# E.g. tasks [0, 1, 2] have counts of [2, 3, 2] respectively, then the counters are:
		# [0 => [], 1 => [], 2 => [0, 2], 3 => [1]], meaning task 0 and 2 have 2 remaining, task 1 has 3 remaining
		# Counters list is 1-indexed, so if the max count is 3, the list should have 4 elements (with max index of 3)
		counters = [[] for i in range(max(counts) + 1)]

		# Populate the counts
		for i in range(len(counts)):
			counters[counts[i]].append(i)

		return counters
