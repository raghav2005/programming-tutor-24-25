#include <stdio.h>

char *mergeAlternately(char *word1, char *word2) {
    int word1_len = strlen(word1);
    int word2_len = strlen(word2);
    int total_len = word1_len + word2_len;
    char *new_word = malloc((total_len + 1) * sizeof(char));

    int i = 0, j = 0, k = 0;
    while (i < word1_len || j < word2_len) {
        if (i < word1_len) {
            *(new_word + k++) = *(word1 + i++);
        }
        if (j < word2_len) {
            *(new_word + k++) = *(word2 + j++);
        }
    }

    *(new_word + k) = '\0';
    return new_word;
}
