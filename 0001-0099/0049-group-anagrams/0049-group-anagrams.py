"""
If 2 strings are anagrams, their sorted version must match up. Use this sorted version as a key in a map, and value is
the list of strings sharing the key (i.e. they are anagrams to one another).

Return values of the map (list of lists) at the end.
"""
class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        groups = {}

        for s in strs:
            key = "".join(sorted(s))
            if key not in groups:
                groups[key] = []
            groups[key].append(s)

        return groups.values()
