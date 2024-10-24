# Week 4

- [Leetcode](#leetcode)
- [Last Week Recap + Fixes](#last-week-recap--fixes)
  - [Python](#python)
  - [C](#c)
- [C Structs](#c-structs)

## Leetcode

No new leetcodes this week - we simply went through the solutions for last week's leetcodes. Refer to [Week 3's README file](../week_3/README.md) to find the solution files.

## Last Week Recap + Fixes

### Python

Refer to [this file](../week_3/oop_learning.py).

- class variables
- overloading

### C

Refer to [this file](../week_3/strings_learning.c).

- shortest way to copy a string in C

## C Structs

We covered the following things in this week's session:

- typedef
  - standalone
  - arrays
  - structs
  - anonymous structs
- what is a struct?
- initialising a struct
  - directly at end of struct definition
  - via struct = {arg1, arg2};
  - via struct = {.attr2 = arg2, .attr1 = arg1};
  - separately via . notation for each attribute
- initalising a struct's attributes
  - strings/arrays (e.g. char []) - strcpy()
  - strings (char *) - normally e.g. via another char \* OR malloc()
- struct as function parameter
  - unlike arrays - whole struct copied rather than just pointer (unless explicitly pass pointer ofc)
- assigning a struct to another
  - acts as memcpy
- struct pointers (with -> notation)
  - strdup() for strings
    - ensure strdup's argument is a const char *
  - struct as an attribute
  - copying struct pointers / pointing to the same struct

> Potentially look at enums, .h files, and -c

NOTE: look into `leaks` command (might need to `brew install leaks` on mac) as an alternative for `valgrind`). If you're on windows, WSL should allow you to install valgrind with `apt install valgrind` or using whatever package manager is available in your version of WSL.

The file [struct\_prep.c](struct_prep.c) contains all examples for everything - I created this before the session, so any code that I forgot to show during the session will be in here.

<!-- 
## Sketches

For the diagrams drawn during the session, refer to [this pdf](sketches.pdf).
 -->
