#include <stdio.h>
#include <stdlib.h>

int main() {

    char* s = "hello";

    int i;
    while(s[++i]);

    printf("%d\n", i); // gives length excluding \0

    char *v = malloc((i + 1) * sizeof(char)); // don't forget about \0
    
    // version 1 - the most intuitive way
    /* int j = 0; */
    /* while (s[j]) { */
    /*     v[j] = s[j]; */
    /*     j++; */
    /* } */
    /* v[j] = '\0'; */

    // version 2 - the most efficient way
    char *temp_src = s, *temp_dest = v;
    while ((*temp_dest++ = *temp_src++)); // essentially doing while ((*temp_dest++ = *temp_src++) != '\0');    

    printf("%s\n", v);

    return 0;
}
