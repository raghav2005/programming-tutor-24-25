class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        word1_len, word2_len = len(word1), len(word2)

        bigger_len = word1_len
        if word2_len > word1_len:
            bigger_len = word2_len

        new_word = ""
        for i in range(bigger_len):
            if i < word1_len:
                new_word += word1[i]
            if i < word2_len:
                new_word += word2[i]

        return new_word


x = Solution()
print(x.mergeAlternately("ace", "bdfghi"))
