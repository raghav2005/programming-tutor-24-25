#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isSubsequence(char* s, char* t) {
    int s_len, t_len, s_ptr, t_ptr;
    s_len = strlen(s), t_len = strlen(t);
    s_ptr = t_ptr = 0;

    if (s_len > t_len) {
        return false;
    }

    while (s_ptr < s_len && t_ptr < t_len) {
        if (*(s + s_ptr) == *(t + t_ptr++)) {
            s_ptr++;
        }
    }

    return s_ptr == s_len;
}

int main() {
    bool ans = isSubsequence("ace", "abcde");
    printf("%s\n", ans ? "true" : "false");

    return 0;
}
