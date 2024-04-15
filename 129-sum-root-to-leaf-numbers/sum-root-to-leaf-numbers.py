# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        def dfs(node,st=""):
            if not node:
                return 0
            elif not node.left and not node.right:
                return int(st+f"{node.val}")
            return dfs(node.left,st+f"{node.val}")+ dfs(node.right,st+f"{node.val}")
        return dfs(root)