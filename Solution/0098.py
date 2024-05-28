# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def checkBST(self, root, low_min, high_max):
        if root == None:
            return True

        if root.val <= low_min or root.val >= high_max:
            return False
        
        return self.checkBST(root.left, low_min, root.val) and self.checkBST(root.right, root.val, high_max)
        
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        return self.checkBST(root, -float("inf"), float("inf"))