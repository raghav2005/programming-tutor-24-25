#include <stdio.h>

int main() {
    // char *s is the same as char* s (both are essentially strings)
    char *s = "hello"; 
    printf("%p\n", s); // address stored in s
    printf("%c\n", *s); // value of the address stored in s

    int i = 0;
    while (s[i] != '\0') { // all strings end with \0
        printf("%c", s[i]); // no newline character to display all results on a single line
        i++;
    }

    int x = 10;
    printf("%d\n", x); // actual value of x
    printf("%p\n", &x); // address of x
    printf("%p\n", &*&x); // *x is the same as x in this case
}
