#include <stdio.h>
#include <stdlib.h>

int main() {

    char* s = "hello";

    int i;
    while(s[++i]);

    printf("%d\n", i);

    char *v = malloc((i + 1) * sizeof(char));
    int j = 0;
    while (s[j]) {
        v[j] = s[j];
        j++;
    }
    v[j] = '\0';

    printf("%s\n", v);

}
