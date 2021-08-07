"""
A trie is basically a tree in which each node can have multiple child nodes, and a flag that marks the end of a word on
this node.

The child nodes can be stored in hash map with letter as keys, or (if the range of child nodes is known, e.g. only 26
lowercase letters) in array with different offsets indicating the letters.

For looking up word or prefix, simply traverse the trie from root to child nodes by following the letters. Break as
soon as a letter is not found in child nodes.
"""
class TrieNode(object):
    def __init__(self):
        self.nodes = {}
        self.end = False

class Trie(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = TrieNode()

    def insert(self, word):
        """
        Inserts a word into the trie.
        :type word: str
        :rtype: None
        """
        node = self.root
        for letter in word:
            # Create child node if not exist
            if letter not in node.nodes:
                node.nodes[letter] = TrieNode()
            node = node.nodes[letter]
        # There is a valid word the ends on this node
        node.end = True

    def search(self, word):
        """
        Returns if the word is in the trie.
        :type word: str
        :rtype: bool
        """
        node = self.root
        for letter in word:
            # If letter not exist as child node, there is no such word since this letter
            if letter not in node.nodes:
                return False
            node = node.nodes[letter]
        # If this node marks the end of a valid word
        return node.end

    def startsWith(self, prefix):
        """
        Returns if there is any word in the trie that starts with the given prefix.
        :type prefix: str
        :rtype: bool
        """
        node = self.root
        for letter in prefix:
            # If letter not exist as child node, there is no such word since this letter
            if letter not in node.nodes:
                return False
            node = node.nodes[letter]
        # Don't care if and word ends on this node, as long as the prefix exist in trie, return true
        return True

# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)