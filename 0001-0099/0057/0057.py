class Solution(object):
	def insert(self, intervals, new):
		"""
		:type intervals: List[List[int]]
		:type new: List[int]
		:rtype: List[List[int]]
		"""
		
		left = []
		right = []
		
		for i in intervals:
			if i[1] < new[0]:
				left.append(i)
			elif i[0] > new[1]:
				right.append(i)
			else:
				# Merge the 2 intervals (expand the new interval)
				new[0] = min(i[0], new[0])
				new[1] = max(i[1], new[1])
		
		return left + [new] + right