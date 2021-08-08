"""
Similar to #208 Implement Trie (Prefix Tree), the difference is when matching words with wildcard, all possible next
letters of current node in the trie need to be DFS explored for a match.

Another approach is to build "." nodes into the trie in the first place, e.g. ading word "bad" looks like:

root - b - a - d
     \   \   \ .
      \   \
       \   . - d
        \    \ .
         .
...

So matching will be simpler. But this approach takes more space, and not performant when adding happend more than
searching (which is the case for LeetCode test data).
"""

class Node(object):
    def __init__(self):
        self.next = {}
        self.end = False

class WordDictionary(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = Node()

    def addWord(self, word):
        """
        :type word: str
        :rtype: None
        """
        node = self.root
        for l in word:
            if l not in node.next:
                node.next[l] = Node()
            node = node.next[l]
        node.end = True

    def search(self, word):
        """
        :type word: str
        :rtype: bool
        """
        return self.searchDfs(word, 0, self.root)

    def searchDfs(self, word, offset, node):
        # If has reached end of word, return if there is word ending on this node
        if offset == len(word):
            return node.end

        l = word[offset]

        # If current letter is wildcard
        if l == ".":
            for c in node.next:
                # Try all next nodes, return true if any of them can match with the remaining word
                if self.searchDfs(word, offset+1, node.next[c]):
                    return True
        # Normal matching of next node
        elif l in node.next:
            return self.searchDfs(word, offset+1, node.next[l])

        return False

# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)