class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        s_len, t_len = len(s), len(t)
        s_ptr, t_ptr = 0, 0

        if s_len > t_len:
            return False
        
        while s_ptr < s_len and t_ptr < t_len:
            if s[s_ptr] == t[t_ptr]:
                s_ptr += 1
            t_ptr += 1
        
        return s_ptr == s_len


x = Solution()
print(x.isSubsequence("ace", "abcde"))
