#include <stdio.h>
/* #include <stdbool.h> */

#define true 1
#define false 0

int main(int argc, char **argv) {
    printf("%d\n", argc);
    for (int i = 0; *(argv + i); i++) {
        printf("%s\n", *(argv + i));
    }

    printf("\n%s\n\n", (argc > 4 ? true : false) 
                      ? "more than 4 args"
                      : "4 or less args"
           );

}
