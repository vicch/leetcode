import collections

class Solution(object):
	def findDuplicate(self, paths):
		"""
		:type paths: List[str]
		:rtype: List[List[str]]
		"""
		# defaultdict doesn't need to check for key presence when accessing
		contentMap = collections.defaultdict(list)

		for path in paths:
			parts = path.split(" ")
			dirName = parts[0]
			for part in parts[1:]:
				# Only split by "(", content will have a trailing ")" but it's universal and doesn't affect comparison
				fileName, content = part.split("(")
				contentMap[content].append(dirName + "/" + fileName)

		return [paths for paths in contentMap.values() if len(paths) > 1]

s = Solution()
print(s.findDuplicate(["root/a 1.txt(abcd) 2.txt(efgh)","root/c 3.txt(abcd)","root/c/d 4.txt(efgh)","root 4.txt(efgh)"]))
print(s.findDuplicate(["root/a 1.txt(abcd) 2.txt(efgh)","root/c 3.txt(abcd)","root/c/d 4.txt(efgh)"]))