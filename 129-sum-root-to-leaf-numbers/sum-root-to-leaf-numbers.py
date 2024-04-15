# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        def dfs(node,st=""):
            tmp = 0
            if node.right:
                tmp += dfs(node.right,st+f"{node.val}")
            if node.left:
                tmp += dfs(node.left,st+f"{node.val}")
            if not node.left and not node.right:
                return int(st+f"{node.val}")
            return tmp
        return dfs(root)