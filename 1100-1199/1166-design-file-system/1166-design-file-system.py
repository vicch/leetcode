"""
This is a natural use case of trie, where each node stores one level of directory, and the value of path ending on that
level. The root node can be the root directory for simplicity, otherwise a list of first-level nodes need to be kept
track of. For n paths with average m levels, the space complexity is O(mn), and time complexity for lookup and insertion
are O(m).

This can also be solved with hashmap, where each prefix of each inserted path is stored as an entry, with the value
being the path value. Space complexity is also O(mn) for a well designed hashing, and lookup is O(1) while insertion is
O(m), because each prefix needs to be looked up.
"""