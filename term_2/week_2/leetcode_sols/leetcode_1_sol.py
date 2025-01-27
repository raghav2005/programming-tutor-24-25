# version 1 - not the best
class Solution1:
    def countBits(self, n):
        ans = [0] * (n + 1)
        for i in range(n + 1):
            ans[i] = bin(i).count('1')
        
        return ans


x = Solution1()
print(x.countBits(5))  # [0,1,1,2,1,2]


# version 2 - best
class Solution2:
    def countBits(self, n):
        ans = [0] * (n + 1)
        for i in range(n + 1):
            ans[i] = ans[i // 2] + (i % 2)
        
        return ans


y = Solution2()
print(y.countBits(5))  # [0,1,1,2,1,2]
