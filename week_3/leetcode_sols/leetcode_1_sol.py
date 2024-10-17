class Solution:
    def reverseWords(self, s: str) -> str:
        return ' '.join([word for word in s.split(' ')[::-1] if word != ''])
    

x = Solution()
print(x.reverseWords("hello my     name is     x"))
