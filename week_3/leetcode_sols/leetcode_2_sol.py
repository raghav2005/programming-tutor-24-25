from typing import List


## version 1
class Solution1:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        prefix_prods, suffix_prods, answer = [1] * n, [1] * n, [1] * n

        prefix_prods[0] = nums[0]
        for i in range(1, n):
            prefix_prods[i] = prefix_prods[i - 1] * nums[i]

        suffix_prods[-1] = nums[-1]
        for i in range(n - 2, -1, -1):
            suffix_prods[i] = suffix_prods[i + 1] * nums[i]

        answer[0] = suffix_prods[1]
        answer[-1] = prefix_prods[-2]
        for i in range(1, n - 1):
            answer[i] = prefix_prods[i - 1] * suffix_prods[i + 1]

        return answer


x = Solution1()
print(x.productExceptSelf([i for i in range(1, 5)]))


## version 2
class Solution2:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        l, r = 1, 1
        ans = [1] * n

        for i in range(n):
            ans[i] *= l
            l *= nums[i]
        for i in range(n - 1, -1, -1):
            ans[i] *= r
            r *= nums[i]

        return ans


y = Solution2()
print(y.productExceptSelf([i for i in range(2, 6)]))
