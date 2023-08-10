"""
There is a simpler approach of using 2 lists:
- One storing text on the left of the cursor, in normal order
- One storing text on the right, in reverse order, i.e. a stack

Adding and removing text is always on left list. And moving cursor left and right is popping and pushing chars between
the 2 lists.
"""
class TextEditor(object):
    def __init__(self):
        self.l1, self.l2 = [], []

    def addText(self, text):
        """
        :type text: str
        :rtype: None
        """
        self.l1.extend(text)

    def deleteText(self, k):
        """
        :type k: int
        :rtype: int
        """
        deleted = min(len(self.l1), k)
        for _ in range(deleted):
            self.l1.pop()
        return deleted

    def cursorLeft(self, k):
        """
        :type k: int
        :rtype: str
        """
        while k != 0 and self.l1:
            k -= 1
            self.l2.append(self.l1.pop())
        return ''.join(self.l1[max(0, len(self.l1) - 10):])

    def cursorRight(self, k):
        """
        :type k: int
        :rtype: str
        """
        while k != 0 and self.l2:
            k -= 1
            self.l1.append(self.l2.pop())
        return ''.join(self.l1[max(0, len(self.l1) - 10):])

# Your TextEditor object will be instantiated and called as such:
# obj = TextEditor()
# obj.addText(text)
# param_2 = obj.deleteText(k)
# param_3 = obj.cursorLeft(k)
# param_4 = obj.cursorRight(k)
