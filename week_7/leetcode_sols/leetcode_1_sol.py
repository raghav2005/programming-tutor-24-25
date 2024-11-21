from collections import Counter

class Solution:
    def closeStrings(self, word1, word2):
        if len(word1) != len(word2):
            return False

        word1_count, word2_count = Counter(word1), Counter(word2)
        word1_freqs, word2_freqs = list(word1_count.values()), list(word2_count.values())
        
        for i in range(26):
            if (min(word1_count[chr(97 + i)], 1) ^ min(word2_count[chr(97 + i)], 1)):
                return False

        word1_freqs.sort()
        word2_freqs.sort()

        return word1_freqs[:] == word2_freqs[:]


x = Solution()
print(x.closeStrings("cabbba", "abbccc"))
