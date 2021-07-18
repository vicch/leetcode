class Solution(object):
	def lengthOfLongestSubstring(self, s):
		"""
		:type s: str
		:rtype: int
		"""
		lastPos = {}
		winStart, maxLen = 0, 0

		for i in range(len(s)):
			if s[i] in lastPos and winStart <= lastPos[s[i]]:
				winStart = lastPos[s[i]] + 1
			else:
				maxLen = max(maxLen, i - winStart + 1)
			
			lastPos[s[i]] = i

		return maxLen

s = Solution()
print(s.lengthOfLongestSubstring(" "))