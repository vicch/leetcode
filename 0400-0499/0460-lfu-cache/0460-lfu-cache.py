"""
[NEED_REVIEW]

Firstly, for O(1) read of cache values by keys, it requires a hashmap. And besides the value, we also need to maintain
the access frequency per key. It could be 2 separate maps, or 1 unified map with the value and frequency in an array
(tuples are immutable).

Secondly, to know which key to evict when capacity is reached, we need to know the global min frequency at any time.
This counter is maintained when new keys are inserted (reset to 1), or when the last key with that frequency is accessed
one more time.

With the min frequency known, we also need to find the key with that frequency. If all frequencies are unique, a
reverse map from frequency to key is enough. But as there are tie situations, each frequency actually maps to a group
of keys with the same frequency.

These keys in the same group need to be ordered by their last access time, so the least recent accessed can be evicted.
Obvisously this transforms into the LRU problem: each frequency group can be implemented as a doubly-linked list, where
the nodes are ordered by their last access time.

Each time a key's frequency increments, the corresponding node is moved to the next group and inserted at the tail. The
node at the head of each frequency group is the least recently accessed key with that frequency.

If OrderedDict() is allowed, it's simpler. Otherwise we need to implement the same data structure as LRU problem.

Time complexity:
- get(): O(1), for hashmap read, and frequency update, which involves hashmap read and doubled-linked list removal and
  insertion.
- put(): O(1), for hashmap insertion or update, and frequency update same as above.

Space complexity:
- O(n), for the hashmaps.
"""
class LFUCache(object):

    def __init__(self, capacity):
        """
        :type capacity: int
        """
        self.capacity = capacity
        self.cache = {}
        self.freq_groups = collections.defaultdict(OrderedDict)
        self.min_freq = 0


    def get(self, key):
        """
        :type key: int
        :rtype: int
        """
        if key not in self.cache:
            return -1
        self._increment_freq(key)
        return self.cache[key][0]


    def put(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: None
        """
        if self.capacity <= 0:
            return

        # Update only
        if key in self.cache:
            self._increment_freq(key)
            self.cache[key][0] = value
            return

        if len(self.cache) == self.capacity:
            self._evict()

        # Insert
        self.cache[key] = [value, 1]
        self.freq_groups[1][key] = -1

        self.min_freq = 1


    def _increment_freq(self, key):
        old_freq = self.cache[key][1]
        new_freq = old_freq + 1

        self.cache[key][1] = new_freq

        self.freq_groups[old_freq].pop(key)
        self.freq_groups[new_freq][key] = -1

        # Optimization: clean up empty frequency group
        if len(self.freq_groups[old_freq]) == 0:
            del self.freq_groups[old_freq]

        # If frequency group corresponding to min freq doesn't exist, it means there is no key with that frequency
        # anymore, and min freq should update to the new freq.
        if self.min_freq not in self.freq_groups:
            self.min_freq = new_freq

    def _evict(self):
        key, _ = self.freq_groups[self.min_freq].popitem(last=False)
        del self.cache[key]
