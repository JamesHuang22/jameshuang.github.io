#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trav-stack.h"

/* (c) Larry Herman, 2017.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

static void test1(void);
static void test2(void);

static void test1(void) {
    Trav_stack trav_stack;

    init(&trav_stack);

    push(&trav_stack, "Kangaroo");
    push(&trav_stack, "Llama");
    push(&trav_stack, "Giraffe");
    push(&trav_stack, "Platypus");
    push(&trav_stack, "Parrot");

    if (size(trav_stack) != 5) {
        printf("Bug found- size() was wrong!\n");
        exit(FOUND_BUG);
    } else clear(&trav_stack);
}

static void test2(void) {
    Trav_stack trav_stack;
    char *element;

    init(&trav_stack);

    push(&trav_stack, "Kangaroo");
    push(&trav_stack, "Llama");
    push(&trav_stack, "Giraffe");
    push(&trav_stack, "Platypus");
    push(&trav_stack, "Parrot");

    element= read(trav_stack);
    if (element == NULL || strcmp(element, "Parrot") != 0) {
        printf("Bug found- read() was wrong!\n");
        exit(FOUND_BUG);
    } else clear(&trav_stack);
}

static void test3(void){
    Trav_stack trav_stack;
    char *str = "aaa";

    init(&trav_stack);
    if(size(trav_stack) != 0 && 
       read(trav_stack) != NULL)
        exit(FOUND_BUG);

    if(push(&trav_stack, str) != 1)
        exit(FOUND_BUG);

    if(strcmp(read(trav_stack),"aaa") != 0)
        exit(FOUND_BUG);

    str = "bcd";

    /* testing to see if the program creates a copy */
    if(strcmp(read(trav_stack),"aaa") != 0)
        exit(FOUND_BUG);

    /* cursor should not down if reach bottom */
    if((down(&trav_stack) != 0))
        exit(FOUND_BUG);

    push(&trav_stack, "b");

    /* push function should preserve cursor position */
    if(strcmp(read(trav_stack),"b") != 0 &&
       size(trav_stack) != 2)
        exit(FOUND_BUG);

    down(&trav_stack);

    if(strcmp(read(trav_stack),"aaa") != 0)
        exit(FOUND_BUG);

    if((down(&trav_stack) != 0))
        exit(FOUND_BUG);

    if(pop(&trav_stack) != 0 && 
       strcmp(read(trav_stack),"aaa") != 0 &&
       size(trav_stack) != 2)
        exit(FOUND_BUG);

    push(&trav_stack, "c");

    if(strcmp(read(trav_stack),"b") != 0 &&
       size(trav_stack) != 3 &&
       pop(&trav_stack) != 1 &&
       size(trav_stack) != 2 &&
       strcmp(read(trav_stack),"aaa") != 0)
        exit(FOUND_BUG);

    push(&trav_stack, "c");

    reset(&trav_stack);
    if(strcmp(read(trav_stack), "c") != 0)
        exit(FOUND_BUG);

    str = read(trav_stack);
    if(pop(&trav_stack) != 1 &&
       read(trav_stack) != "b" &&
       size(trav_stack) != 2 &&
       pop(&trav_stack) != 1 &&
       read(trav_stack) != "aaa" &&
       size(trav_stack) != 1 && 
       pop(&trav_stack) != 1 &&
       read(trav_stack) != NULL &&
       size(trav_stack) != 0)
        exit(FOUND_BUG);

    clear(&trav_stack);
    init(&trav_stack);

    if(strcmp(str, "c") != 0)
        exit(FOUND_BUG);
    printf("test complete!\n");

    /* clear the graph and see whether it is a copy */
}




int main() {
    test1();
    test2();
    test3();

    printf("No bugs were detected!\n");

    return CORRECT;
}
