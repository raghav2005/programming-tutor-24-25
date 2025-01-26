class Solution:
    def is_vowel(self, c):
        if c in ['a', 'e', 'i', 'o', 'u']:
            return 1
        return 0

    def maxVowels(self, s, k):
        vowel_bool_list = [self.is_vowel(c) for c in s]
        curr_val = sum(vowel_bool_list[:k])
        max_val = curr_val

        for i in range(len(s) - k):
            curr_val = curr_val - vowel_bool_list[i] + vowel_bool_list[i + k]
            if curr_val > max_val:
                max_val = curr_val
        
        return max_val


x = Solution()
print(x.maxVowels("abciiidef", 3))
