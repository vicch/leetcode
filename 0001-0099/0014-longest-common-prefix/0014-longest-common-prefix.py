"""
The goal is to find the longest common sub-string starting with index 0 in each string. So use a running pointer that
moves from index 0 onward, and stop when any string doesn't have this index (because it's short) or any string's
current letter doesn't match with first string (which is arbitrary, but since the prefix is common across all strings,
it doesn't matter which string is used for comparison).
"""

class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """

        def getPrefixLength():
            # Index keeps growing until it is found that any string is shorter than the index, or any letter doesn't
            # match the corresponding letter of first string (any string actuall, but just use first string as base).
            for i in range(len(strs[0])):
                for j in range(1, len(strs)):
                    # Cannot extend the common prefix any further, break and return
                    if len(strs[j]) <= i or strs[j][i] != strs[0][i]:
                        return i

        # The index stops on the value where it's no longer a common prefix, by using that as right boundary (which is
        # exclusive) for list slicing returns the correct common prefix.
        return strs[0][:getPrefixLength()]
