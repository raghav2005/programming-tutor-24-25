#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Point {
    int x;
    int y;
    char *name;
} Point;

// can use function signatures without explicit argument names - will look at this more next week when covering header files
void create_struct(Point);
Point return_struct(int, int, char*);
Point* create_point_ptr(int, int, const char*);

int main() {
    /* Point p1 = {.y = 7, .x = 5}; // can be allocated in any order
    printf("x: %d, y: %d\n", p1.x, p1.y);

    char *s = "hello"; // pointers can be used like this, but if an array, then needs to use strcpy
    p1.name = s;
    printf("%s\n", p1.name);

    printf("mem outside: %p\n", &p1);
    create_struct(p1);
    printf("outside function x: %d\n", p1.x);

    Point p2 = {1, 2}; // whatever is included in {} in order - doesn't need to be all attributes
    p1 = p2; // memcpy
    p2.x = 5;
    printf("p1.x: %d, p1.y: %d, p2.x: %d, p2.y: %d\n", p1.x, p1.y, p2.x, p2.y);

    int i = 10;
    p1.z = &i;

    int j = 20;
    p2.z = &j;
    printf("p1.z: %d, p2.z: %d\n", *p1.z, *p2.z);

    int a = 30;
    p2.z = &a;
    p1 = p2;
    printf("p1.z: %d, p2.z: %d\n", *p1.z, *p2.z); */

    Point p2 = return_struct(1, 2, "hi");
    printf("x: %d, y: %d, s: %s\n", p2.x, p2.y, p2.name);

    Point *p3 = create_point_ptr(3, 4, "hello");
    printf("x: %d, y: %d, s: %s\n", p3->x, p3->y, p3->name);
    
    Point *p4 = create_point_ptr(5, 6, "bye");
    printf("x: %d, y: %d, s: %s\n", p4->x, p4->y, p4->name);

    // look at the following code block - this is the wrong way to assign a struct to another struct
    // this is mainly because there's no longer any existing reference to any memory that was allocated
    // on the heap, so you cannot free it at the end - valgrind will give you an error
    // you also can't try to copy that memory address as this is a shallow copy to just the first value
    // rather than the full thing - if it was a deep copy, that would be fine, but we cannot do this
    
    /* char *p3_name_cpy = p3->name; // creates a shallow copy - not exactly getting the full p3.name
    p3 = p4;
    *(p4->name + 1) = 't';
    printf("p3: x: %d, y: %d, s: %s\n", p3->x, p3->y, p3->name);
    printf("p4: x: %d, y: %d, s: %s\n", p4->x, p4->y, p4->name);
    free(p4->name);
    free(p4);
    free(p3); // same as free(p4) so will give an error as that memory has already been freed */

    // instead, do the following - free the old struct's memory first, then copy whatever is needed
    
    free(p3->name);
    free(p3);
    p3 = p4;
    *(p4->name + 1) = 't';
    printf("p3: x: %d, y: %d, s: %s\n", p3->x, p3->y, p3->name);
    printf("p4: x: %d, y: %d, s: %s\n", p4->x, p4->y, p4->name);
    free(p4->name);
    free(p4);

    return 0;
}

void create_struct(Point p) {
    printf("mem inside: %p\n", &p);
    p.x = 10;
    printf("inside function x: %d\n", p.x);
}

Point return_struct(int x, int y, char* s) {
    Point p = {x, y};
    p.name = s;
    return p;
}

Point* create_point_ptr(int x, int y, const char* s) {
    Point *p = (Point *)malloc(sizeof(Point)); // the (Point *) is not strictly necessary but good practice to cast types with malloc()
    p->x = x;
    p->y = y;
    p->name = strdup(s); // allocates memory on the heap and creates a copy, returning a pointer to it
    return p;
}
