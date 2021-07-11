class Solution(object):
	def findErrorNums(self, nums):
		"""
		:type nums: List[int]
		:rtype: List[int]
		"""
		counts = [0] * len(nums)
		for n in nums:
			counts[n - 1] += 1

		a, b = None, None
		for i in range(len(nums)):
			# Find dup number
			if counts[i] == 2:
				a = i + 1
			# Find missing number
			if counts[i] == 0:
				b = i + 1
			# If both found, break
			if a and b:
				break
		
		return [a, b]