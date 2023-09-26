"""
The key lookup naturally requires a hashmap, while the timestamp lower bound lookup can be binary search against the
list of time-based values, where the timestamp-value pairs are sorted. The insertion of new K-V pairs can be simple
append because the timestamps are natrually sorted as set() is called.

Time: set = O(1), get = O(logm) where m is number of values per key
Space: O(mn) where n is number of keys
"""
class TimeMap(object):

    def __init__(self):
        self.cache = {}

    def set(self, key, value, timestamp):
        """
        :type key: str
        :type value: str
        :type timestamp: int
        :rtype: None
        """
        if key not in self.cache:
            self.cache[key] = [(0, "")]
        self.cache[key].append((timestamp, value))

    def get(self, key, timestamp):
        """
        :type key: str
        :type timestamp: int
        :rtype: str
        """
        if key not in self.cache:
            return ""
        return self._lowerBoundValue(key, timestamp)

    def _lowerBoundValue(self, key, timestamp):
        l, r = 0, len(self.cache[key]) - 1
        while l <= r:
            m = (l + r) // 2
            if self.cache[key][m][0] > timestamp:
                r = m - 1
            else:
                l = m + 1
        return self.cache[key][r][1]
