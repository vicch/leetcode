"""
It is natural to use a double-linked list: each node stores a char. Cursor points to one node and can move forward or
backward, while inserting and removing nodes with O(1) complexity.

The complexity comes from linked list operations such as insertion and deletion.
"""
class TextNode(object):
    def __init__(self, char):
        self.char = char
        self.prev = None
        self.next = None

class TextEditor(object):
    def __init__(self):
        self.head, self.tail = TextNode(''), TextNode('')
        self.head.next, self.tail.prev = self.tail, self.head
        # Cursor points to the right of current node, starts with head so inserting is appending to this node.
        self.cursor = self.head

    def addText(self, text):
        """
        :type text: str
        :rtype: None
        """
        for c in text:
            self._append(c)

    def deleteText(self, k):
        """
        :type k: int
        :rtype: int
        """
        deleted = 0
        for i in range(k):
            if not self._delete():
                break
            deleted += 1
        return deleted

    def cursorLeft(self, k):
        """
        :type k: int
        :rtype: str
        """
        for i in range(k):
            if not self._moveLeft():
                break
        return self._getLeft(10)

    def cursorRight(self, k):
        """
        :type k: int
        :rtype: str
        """
        for i in range(k):
            if not self._moveRight():
                break
        return self._getLeft(10)
    
    def _append(self, char):
        node = TextNode(char)
        node.prev = self.cursor
        node.next = self.cursor.next
        self.cursor.next.prev = node
        self.cursor.next = node

        self.cursor = self.cursor.next
    
    def _delete(self):
        if self.cursor == self.head:
            return False
        self.cursor.prev.next = self.cursor.next
        self.cursor.next.prev = self.cursor.prev
        self.cursor = self.cursor.prev
        return True

    def _moveLeft(self):
        if self.cursor != self.head:
            self.cursor = self.cursor.prev
            return True
        return False
    
    def _moveRight(self):
        if self.cursor.next != self.tail:
            self.cursor = self.cursor.next
            return True
        return False

    def _getLeft(self, l):
        c = self.cursor
        for i in range(l - 1):
            if c == self.head or c.prev == self.head:
                break
            c = c.prev
        s = ''
        while c != self.cursor:
            s += c.char
            c = c.next
        return s + self.cursor.char

# Your TextEditor object will be instantiated and called as such:
# obj = TextEditor()
# obj.addText(text)
# param_2 = obj.deleteText(k)
# param_3 = obj.cursorLeft(k)
# param_4 = obj.cursorRight(k)
