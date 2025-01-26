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
    def leafSimilar(self, root1, root2) -> bool:
        self.arr = []
        self.get_leaves(root1)
        
        x = self.arr
        self.arr = []

        self.get_leaves(root2)
        
        return x == self.arr
        
    def get_leaves(self, node):

        if node.left is None and node.right is None:
            self.arr.append(node.val)
            return
        
        else:
            if node.left:
                self.get_leaves(node.left)
            if node.right:
                self.get_leaves(node.right)

        return


x = Solution()
print(x.leafSimilar(create_tree([3,5,1,6,2,9,8,None,None,7,4]), create_tree([3,5,1,6,7,4,2,None,None,None,None,None,None,9,8])))
