#include <stdio.h>
#include <limits.h>
#include "add_func.h" // if doing it this way, need to run `gcc c_learning.c add_func.c -o c_learning`. otherwise, could #include "add_func.c" and then run `gcc c_learning.c -o c_learning`. However, including .c files is bad practice

#define true 1
#define false 0

// const int ADD_CONST = 10; // could be here or defined in add_func.c - doesn't make a difference as both .c files are linked together (I've put it there for now)

// Define an enum for days of the week
typedef enum Day {
    SUNDAY,    // 0
    MONDAY,    // 1
    TUESDAY,   // 2
    WEDNESDAY, // 3
    THURSDAY,  // 4
    FRIDAY,    // 5
    SATURDAY   // 6
} Day;

int main(int argc, char **argv) {

    printf("There is/are %d input(s):\n", argc);

    for (int i = 0; *(argv + i); i++) {
        printf("%s\n", *(argv + i));
    }


    printf("\n%s\n\n", (argc > 4 ? true : false) 
                      ? "more than 4 args"
                      : "4 or less args"
           );

    unsigned int mask = 0b1010;
    printf("%d\n\n", mask);

    printf("%d\n", mask & 2); // 0b0010
    // random question - how would you check if a number is even or odd using bitwise operators?
    printf("%d\n", mask | 5); // 0b0101
    printf("%d\n\n", mask ^ 0b1101);

    // try to flip the 4 least significant bits of mask so that we get 5 i.e. 0b0101;
    printf("%d\n", ~mask); // 0b...11110101
    printf("%u\n\n", ~mask); // still doesn't work
    unsigned int mask_cpy = mask;
    mask_cpy ^= 0b1111;
    printf("%d\n\n", mask_cpy);

    printf("%d\n", mask << 2); // mask * 4
    printf("%d\n\n", mask >> 2); // mask / 4 (truncated)

    int a = 1;
    unsigned int b = 1u;
    int signed_neg = -1;
    unsigned int unsigned_neg = 1u - 2u;

    printf("size of a (1): %zu bytes\n", sizeof(a));
    printf("size of b (1u): %zu bytes\n\n", sizeof(b));

    printf("1u - 2u (as int - 1) = %d\n", signed_neg); // if i changed signed_neg to unsigned_neg the output would be the same because %d would be promoting unsigned_neg to a signed int
    printf("1u - 2u = %u\n\n", unsigned_neg);


    printf("INT_MAX (signed): %d\n", INT_MAX);
    printf("INT_MAX + 1 = %d\n", INT_MAX + 1); // overflow - undefined behavior for signed int
    printf("UINT_MAX (unsigned): %u\n", UINT_MAX);
    printf("UINT_MAX + 1 = %u\n\n", UINT_MAX + 1); // wraps around to 0 for unsigned int

    Day today = WEDNESDAY; // if no typedef, enum Day today = WEDNESDAY;
    switch (today) {
        case SUNDAY:
            printf("It's Sunday!");
            break;
        case MONDAY:
            printf("It's Monday!");
            break;
        case TUESDAY:
            printf("It's Tuesday!");
            break;
        case WEDNESDAY:
            printf("It's Wednesday!");
            break;
        case THURSDAY:
            printf("It's Thursday!");
            break;
        case FRIDAY:
            printf("It's Friday!");
            break;
        case SATURDAY:
            printf("It's Saturday!");
            break;
        default:
            printf("Invalid day!");
    }
    printf(" that is day number %d in the week.\n\n", today);
    // printf("the day is %s\n", today); // this will NOT work

    printf("4 + 5 = %d\n", add(4, 5));
    printf("3 + %d = %d\n", ADD_CONST, add_a_const(3));


   return 0;
}
