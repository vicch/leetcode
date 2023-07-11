class Solution(object):
    def postorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if not root:
            return []

        left = self.postorderTraversal(root.left) if root.left else []
        right = self.postorderTraversal(root.right) if root.right else []

        return left + right + [root.val]
