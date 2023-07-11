class Solution(object):
    def preorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if not root:
            return []

        left = self.preorderTraversal(root.left) if root.left else []
        right = self.preorderTraversal(root.right) if root.right else []

        return [root.val] + left + right
