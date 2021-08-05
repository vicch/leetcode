"""
DFS approach can (de)serialize the root and child nodes via recursions.
"""
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.

        :type root: TreeNode
        :rtype: str
        """
        if not root:
            return None
        return [root.val, self.serialize(root.left), self.serialize(root.right)]


    def deserialize(self, data):
        """Decodes your encoded data to tree.

        :type data: str
        :rtype: TreeNode
        """
        if not data or data[0] is None:
            return None

        root = TreeNode(data[0])
        # data[1] will pass the offset 1 of current list as offset 0 to the next level recursion. And recursively it's
        # gonna pass the offset 1 of the given list to next level.
        root.left = self.deserialize(data[1])
        root.right = self.deserialize(data[2])

        return root

# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))
