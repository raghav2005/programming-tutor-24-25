#include <stdio.h>
#include <stdlib.h>
// #include <string.h>

int gcd(int a, int b) {
    int temp;

    if (a < b) {
        temp = a;
        a = b;
        b = temp;
    }

    while (b != 0) {
        temp = a % b;
        a = b;
        b = temp;
    }

    return a;
}

int len_of_str(char* str) {
    int len = 0;
    while (*(str + ++len) != '\0');
    return len;
}

char* concat_strs(char* str1, char* str2) {
    // strlen
    int str1_len = len_of_str(str1);
    int str2_len = len_of_str(str2);

    int total_len = str1_len + str2_len + 1;
    char* total = malloc(total_len * sizeof(char));

    int i = 0, j = 0;
    while (*(str1 + i) != '\0') {
        *(total + i) = *(str1 + i);
        i++;
    }
    while (*(str2 + j) != '\0') {
        *(total + i + j) = *(str2 + j);
        j++;
    }
    *(total + i + j) = '\0';

    return total;
}

char* gcdOfStrings(char* str1, char* str2) {
    // strcat
    char* total_1 = concat_strs(str1, str2);
    char* total_2 = concat_strs(str2, str1);

    // strcmp
    int is_same = 1;
    int total_len = 0;
    for (int i = 0; *(total_1 + i) != '\0'; i++) {
        total_len++;
        if (*(total_1 + i) != *(total_2 + i)) {
            is_same = 0;
            break;
        }
    }

    char* result = (char*) malloc((total_len + 1) * sizeof(char));

    if (is_same) {
        int gcd_len = gcd(len_of_str(str1), len_of_str(str2));
        for (int i = 0; i < gcd_len; i++) {
            *(result + i) = *(str1 + i);
        }
        *(result + gcd_len) = '\0';
    } else {
        *(result + 0) = '\0';
    }

    free(total_1);
    free(total_2);

    return result;
}
