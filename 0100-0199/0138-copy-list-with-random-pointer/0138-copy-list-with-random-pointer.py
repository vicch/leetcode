"""
Building new linked list just with the normal "next" links is straightforward.

For building the "random" links, the key is to identify and map the corresponding nodes in the old and new lists, so
that for any "random" link in the old list, we can find the corresponding node in the new list that should be pointed
to by "random" link in the new list.

While building the new list in the first run, use a hash map to store mapping between nodes in the old and new lists
that are corresponding to each other. So it can be used in the second run.
"""

"""
# Definition for a Node.
class Node:
    def __init__(self, x, next=None, random=None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution(object):
    def copyRandomList(self, head):
        """
        :type head: Node
        :rtype: Node
        """
        cache = {}
        dummy = Node(0, head)

        # First run, build normal link ("next" link) for new list based on old list
        p1, p2 = head, dummy
        while p1:
            p2.next = Node(p1.val)
            # Mapping from old list's node to new list's corresponding node
            cache[p1] = p2.next
            p1, p2 = p1.next, p2.next

        # Second run, build random link for new list based on old list
        p1, p2 = head, dummy.next
        while p1:
            if p1.random:
                # Find node in the new list corresponding to the "random" node in old list
                p2.random = cache[p1.random]
            p1, p2 = p1.next, p2.next

        return dummy.next
