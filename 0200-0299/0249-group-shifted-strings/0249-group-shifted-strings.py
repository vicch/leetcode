"""
Two strings fall into the same group, if they can be un-shifted into the same string that starts with "a". So simply
compute this un-shifted version for all strings, and use it as key to group the strings.

It can be considered as "hashing" the shifted strings towards the base string.

Time: O(nm), n being number of strings, m being average length or strings, because each char needs to be shifted.
Space: O(nm), for the hash table.
"""
class Solution(object):
    def groupStrings(self, strings):
        """
        :type strings: List[str]
        :rtype: List[List[str]]
        """
        groups = collections.defaultdict(list)
        # Group all strings by aligned versions.
        for s in strings:
            aligned = self._align(s)
            groups[aligned].append(s)
        return groups.values()

    def _align(self, string):
        # The offset between first char and "a", all chars need to be shifted by this value.
        offset = ord(string[0]) - ord('a')
        chars = []
        for c1 in string:
            c2 = ord(c1) - offset
            # If char falls out of alphabetic range, rotate it into the range.
            if c2 < ord('a'):
                c2 += 26
            chars.append(chr(c2))
        return ''.join(chars)
