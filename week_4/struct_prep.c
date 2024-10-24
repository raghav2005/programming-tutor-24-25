#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char a_name[12];

struct Coord
{
    a_name name;
    int x;
    char *new_name;
};

typedef struct Coord Coord; // OR typedef struct {} Coord

/* struct Point { */
/*     int x; */
/*     int y; */
/* } p1, p2, p3; */

typedef struct List {
    int *vals;
} List;

typedef struct Person Person;
struct Person {
    char *name;
    int age;
    Person *next; // if usual typedef struct Person {} Person, then this needs to be struct Person
};

void init_coord(struct Coord);
struct Coord init_coord_2(struct Coord);
Person* createPerson(const char*, int, Person*);

int main() {
    struct Coord my_coord;

    /* my_coord.name = "first0"; */
    strcpy(my_coord.name, "first");
    my_coord.x = 5;
    printf("%s, %d\n", my_coord.name, my_coord.x);

    my_coord.name[0] = 'b';
    printf("%s, %d\n", my_coord.name, my_coord.x);
    printf("address: %p\n\n", &my_coord);

    char c = 'c';
    *(my_coord.name) = c;
    // the following gives an error - referring to whole array rather than 0th element
    /* char c2 = 'h'; */
    /* my_coord.name = c2; */
    
    init_coord(my_coord);
    printf("address: %p\n", &my_coord);
    printf("%s, %d\n\n", my_coord.name, my_coord.x);

    my_coord = init_coord_2(my_coord);
    printf("%s, %d\n", my_coord.name, my_coord.x);
    printf("address: %p\n\n", &my_coord);

    Coord new_coord;
    char *s = "hello";
    new_coord.new_name = s;
    printf("%s, %d\n", new_coord.new_name, new_coord.x);

    Coord another = {"hi", 7, "bye"};
    printf("%s, %d, %s\n", another.name, another.x, another.new_name);

    Coord another2 = {.x = 7, .new_name = "hello", .name = "goodbye"};
    printf("%s, %d, %s\n", another2.name, another2.x, another2.new_name);

    another = another2; // memcpy
    printf("%s, %d, %s\n", another.name, another.x, another.new_name);

    List list1, list2;
    list1.vals = malloc(sizeof(int) * 2);
    list2.vals = malloc(sizeof(int) * 2);
    for (int i = 0; i < 2; i++) {
        *(list1.vals + i) = i;
        *(list2.vals + i) = 10 - i;
    }

    for (int i = 0; i < 2; i++)
        printf("list1[%d]: %d, list2[%d]: %d\n", i, *(list1.vals + i), i, *(list2.vals + i));

    int *copy_list1_vals = list1.vals;
    list1 = list2; // or list1.vals = list2.vals;
    for (int i = 0; i < 2; i++)
        printf("list1[%d]: %d, list2[%d]: %d\n", i, *(list1.vals + i), i, *(list2.vals + i));

    list2.vals[1] = 8;
    for (int i = 0; i < 2; i++)
        printf("list1[%d]: %d, list2[%d]: %d\n", i, *(list1.vals + i), i, *(list2.vals + i));

    free(list2.vals);
    free(copy_list1_vals);


    Person *firstPerson = createPerson("Raghav", 19, NULL);
    printf("\n%s, %d, %p\n", firstPerson->name, firstPerson->age, firstPerson->next);

    Person firstPersonVal = *firstPerson;
    printf("%s, %d, %p\n\n", firstPersonVal.name, firstPersonVal.age, firstPersonVal.next);
    firstPersonVal.age = 20;
    printf("%s, %d, %p\n", firstPerson->name, firstPerson->age, firstPerson->next);
    printf("%s, %d, %p\n", firstPersonVal.name, firstPersonVal.age, firstPersonVal.next);

    Person *firstPersonVal2 = firstPerson;
    printf("%s, %d, %p\n\n", firstPersonVal2->name, firstPersonVal2->age, firstPersonVal2->next);
    firstPersonVal2->age = 21;
    printf("%s, %d, %p\n", firstPerson->name, firstPerson->age, firstPerson->next);
    printf("%s, %d, %p\n", firstPersonVal2->name, firstPersonVal2->age, firstPersonVal2->next);
    
    return 0;
}

void init_coord(struct Coord coord) {
    printf("address: %p\n", &coord);
    printf("%s, %d\n", coord.name, coord.x);

    coord.x = 7;
    printf("%s, %d\n", coord.name, coord.x);

    strcpy(coord.name, "second");
    printf("%s, %d\n", coord.name, coord.x);
    printf("address: %p\n\n", &coord);
}

struct Coord init_coord_2(struct Coord coord) {
    printf("address: %p\n", &coord);
    coord.x = 12;
    strcpy(coord.name, "third");

    printf("%s, %d\n\n", coord.name, coord.x);

    return coord;
}

Person* createPerson(const char *name, int age, Person *next) {
    Person *person = (Person *)malloc(sizeof(Person));
    person->name = strdup(name); // pointers - same problem as arrays last time so needs to be stored in heap (strdup creates a copy in the heap and return the address of the first val)
    person->age = age;
    person->next = next; // usually just initialise to NULL here or don't even need that

    return person;
}
