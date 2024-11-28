# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def create_tree(arr):
    root = TreeNode(arr[0])
    queue = [root]
    i = 1

    while i < len(arr):
        curr_node = queue.pop(0)

        if arr[i]:
            curr_node.left = TreeNode(arr[i])
            queue.append(curr_node.left)
        
        i += 1

        if i < len(arr) and arr[i]:
            curr_node.right = TreeNode(arr[i])
            queue.append(curr_node.right)
        
        i += 1

    return root


class Solution:
    def longestZigZag(self, root):
        self.curr_max = 0

        if root.left:
            self.dfs(root.left, 0, 1)
        
        if root.right:
            self.dfs(root.right, 1, 1)
        
        return self.curr_max

    def dfs(self, node, curr_dir, length):
        if not node:
            return

        self.curr_max = max(self.curr_max, length)

        if curr_dir == 0: # left
            self.dfs(node.right, 1, length + 1)
            self.dfs(node.left, 0, 1)
        else: # right
            self.dfs(node.left, 0, length + 1)
            self.dfs(node.right, 1, 1)


x = Solution()
print(x.longestZigZag(create_tree([1,None,1,1,1,None,None,1,1,None,1,None,None,None,1])))
