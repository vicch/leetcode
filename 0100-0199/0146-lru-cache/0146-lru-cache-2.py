"""
[NEED_REVIEW]

Same solution, but implement a custom doubly-linked list to simplify LRU logic. This can be swappable with other types
such as deque.
"""
class Node:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.prev = None
        self.next = None

class DoublyLinkedList:
    def __init__(self):
        self.head = Node(0, 0)  # Dummy head node
        self.tail = Node(0, 0)  # Dummy tail node
        self.head.next = self.tail
        self.tail.prev = self.head

    def add_to_head(self, node):
        """Add a node right after the head (most recently used)."""
        node.next = self.head.next
        node.prev = self.head
        self.head.next.prev = node
        self.head.next = node

    def remove(self, node):
        """Remove a node from the list."""
        prev_node = node.prev
        next_node = node.next
        prev_node.next = next_node
        next_node.prev = prev_node

    def remove_from_tail(self):
        """Remove the least recently used node (node before the tail)."""
        lru_node = self.tail.prev
        self.remove(lru_node)
        return lru_node

class LRUCache:
    def __init__(self, capacity):
        self.capacity = capacity
        self.cache = {}  # Dictionary to hold key -> node
        self.list = DoublyLinkedList()  # Doubly linked list to maintain order

    def get(self, key):
        if key in self.cache:
            node = self.cache[key]
            # Move the accessed node to the head (most recently used)
            self.list.remove(node)
            self.list.add_to_head(node)
            return node.value
        return -1

    def put(self, key, value):
        if key in self.cache:
            # Update the value and move the node to the head
            node = self.cache[key]
            node.value = value
            self.list.remove(node)
            self.list.add_to_head(node)
        else:
            # Add new node
            if len(self.cache) >= self.capacity:
                # Evict the least recently used node
                lru_node = self.list.remove_from_tail()
                del self.cache[lru_node.key]

            # Create a new node and add to head
            new_node = Node(key, value)
            self.list.add_to_head(new_node)
            self.cache[key] = new_node
