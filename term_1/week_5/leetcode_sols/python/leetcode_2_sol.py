class Solution:
    def maxArea(self, height):
        ans, l, r = 0, 0, len(height) - 1

        while l < r:
            dist = r - l
            
            if height[l] >= height[r]:
                ans = max(ans, height[r] * dist)
                r -= 1
            else:
                ans = max(ans, height[l] * dist)
                l += 1

        return ans


x = Solution()
print(x.maxArea([1, 8, 6, 2, 5, 4, 8, 3, 7])) # ans = 49
