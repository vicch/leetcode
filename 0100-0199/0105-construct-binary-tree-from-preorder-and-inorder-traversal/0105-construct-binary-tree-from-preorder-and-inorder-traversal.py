"""
Consider the preorder and inorder arrays of a tree:

Preorder: 3 9 20 15 7
Inorder:  9 3 15 20 7

First element of the preorder array is always the root of the tree. By looking up this value (since all values are
unique, there will be only one correct location) in the inorder array, the left and right child trees can be identified:

   9 | 3    | 15 20 7
Left | Root | Right

So that we know length of the left and right trees, then we can identify the left and right trees in the preorder array:

   3 | 9    | 20 15 7
Root | Left | Right

By identifying the left and right trees in both arrays, the left and right trees can be built recursively by passing
these boundaries to next level.
"""
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        l = len(preorder)

        # A cache to store the locations of each value in the inorder array, to speed up searching
        cache = {}
        for i in range(l):
            cache[inorder[i]] = i

        # Input are the ranges (start and end indexes) of the tree's representation in the preorder and inorder arrays
        def buildTreeDfe(px, py, ix, iy):
            # Border check
            if px > py or ix > iy:
                return None

            # Root value is always the first element in preorder range
            value = preorder[px]
            # Find offset of the root node's value in the inorder array
            offset = cache[value]
            # Length of the left tree of current tree
            llen = offset - ix

            root = TreeNode(value)
            root.left = buildTreeDfe(px+1, px+llen, ix, offset-1)
            root.right = buildTreeDfe(px+llen+1, py, offset+1, iy)

            return root

        # Kick off the recursion by passing in the whole range of the arrays
        return buildTreeDfe(0, l-1, 0, l-1)
