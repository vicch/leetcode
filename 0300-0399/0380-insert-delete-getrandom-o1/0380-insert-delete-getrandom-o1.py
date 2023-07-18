"""
Set or dict provides read/write and existence check of O(1). For random element, the randomness needs to come from
random number generator, so we need to use this random number as a sequence or offset, to map it to an existing element,
which can be achieved via an array.

The tricky part is on removal: we need to re-arrange the array so a random value still maps to one element. A naive way
is to move all element subsequent to the removed one up by one location, which will be O(n). The key is that we don't
need to maintain the order of elements in the list, so we can simply move the last element up to fill in the location
of the removed one.

To do this, we need to know the location of each element in the list with O(1) time, which can be achieved via dict,
where the entry keys are element values, and entry values are the element indexes in the list.
"""
import random

class RandomizedSet(object):

    def __init__(self):
        self.list = []
        self.map = {}

    def insert(self, val):
        """
        :type val: int
        :rtype: bool
        """
        if val in self.map:
            return False
        
        # Append value to the list, and remember its index
        self.list.append(val)
        self.map[val] = len(self.list) - 1

        return True
        

    def remove(self, val):
        """
        :type val: int
        :rtype: bool
        """
        if val not in self.map:
            return False
        
        # Index of the element being removed
        idx = self.map[val]

        # Current last element in the list
        last = self.list[-1]

        # Move last element to the vacated index
        self.list[idx] = last
        self.list.pop()

        # Update the moved element's index
        self.map[last] = idx

        # Don't forget to unset the removed element
        self.map.pop(val)

        return True

    def getRandom(self):
        """
        :rtype: int
        """
        # random.choice(seq) also works, but randint() is more generic
        return self.list[random.randint(0, len(self.list) - 1)]

# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
