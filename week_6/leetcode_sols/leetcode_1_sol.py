## version 1 - works, but quite slow and will exceed time limit on leetcode
class Solution1:
    def findMaxAverage(self, nums, k):
        max_val = float('-inf') # most negative number you can have in Python (float('inf') for most positive)

        for i in range(len(nums) - k + 1):
            max_val = max(max_val, sum(nums[i : i + k]) / k)

        return max_val


x = Solution1()
print(x.findMaxAverage([-6, -3, -4, -2, -7, -1], 3))


## version 2
class Solution2:
    def findMaxAverage(self, nums, k):
        curr_val = sum(nums[:k])
        max_val = curr_val

        for i in range(len(nums) - k):
            curr_val = curr_val - nums[i] + nums[i + k]
            if curr_val > max_val:
                max_val = curr_val

        return max_val / k


y = Solution2()
print(y.findMaxAverage([-6, -3, -4, -2, -7, -1], 3))
