// the #ifndef, #define, and #endif are used so that we check for the case where the same header file is imported multiple times unnecessarily
#ifndef ADD_FUNC_H
#define ADD_FUNC_H

// function declarations
int add(int, int);
int add_a_const(int);

// extern variable declarations - extern tells other files (which import this header file) that this variable exists, but it doesn't explicitly allocate the memory for this (the actual definition should be done in the .c file)
extern const int ADD_CONST;

#endif // ADD_FUNC_H
