"""
To begin with, we need a map/dict for O(1) lookup of any key.

Then for the LRU logic, we need to know the order of "least to most recently used" for all the keys, so that:
- when capacity will be exceeded, we know which node to remove
- and after this node is removed, which node is the next to be removed

So we need an internal ordered list of the keys, and we need to constantly re-order the keys when one of them is used.
However with this ordered list, we don't need to get the "n-th recently used" key, we only need the "least and most
recently used" keys. Such requirements lead to the usage of a double-linked list, which has O(1) for re-ordering.

With the double-linked list:
- when a key is used, it's moved to the "most recently used" end
- when a key needs to be removed, remove the one at the "least recently used" end

To simplify the double-linked list handling (of empty checks etc.), use dummy nodes at the head and tail.
"""
class LRUCache(object):

    def __init__(self, capacity):
        """
        :type capacity: int
        """
        self.nodes = dict()
        self.capacity = capacity
        # Dummy nodes
        self.head, self.tail = LRUNode(0, 0), LRUNode(0, 0)
        self.head.next = self.tail
        self.tail.prev = self.head

    def get(self, key):
        """
        :type key: int
        :rtype: int
        """
        if key not in self.nodes:
            return -1

        node = self.nodes[key]

        # Move node to head = remove from list + insert to head
        self.removeNode(node)
        self.insertHead(node)

        return node.value

    def put(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: None
        """
        if key in self.nodes:
            node = self.nodes[key]
            node.value = value
            self.removeNode(node)
            self.insertHead(node)
            return

        if len(self.nodes) >= self.capacity:
            self.removeTail()

        node = LRUNode(key, value)
        self.nodes[key] = node
        self.insertHead(node)

    def insertHead(self, node):
        node.next = self.head.next
        node.prev = self.head
        self.head.next = node
        node.next.prev = node

    def removeTail(self):
        node = self.tail.prev
        del self.nodes[node.key]
        self.removeNode(node)

    def removeNode(self, node):
        node.prev.next = node.next
        node.next.prev = node.prev

class LRUNode(object):
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.prev = None
        self.next = None
