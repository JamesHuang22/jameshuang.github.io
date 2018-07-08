#if !defined(TRAV_STACK_H)
#define TRAV_STACK_H

/* (c) Larry Herman, 2017.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

#include "trav-stack-datastructure.h"

#define CORRECT 1
#define FOUND_BUG 2

void init(Trav_stack *const trav_stack);
int push(Trav_stack *const trav_stack, const char new_element[]);
int size(Trav_stack trav_stack);
int pop(Trav_stack *const trav_stack);
int down(Trav_stack *const trav_stack);
void reset(Trav_stack *const trav_stack);
char *read(Trav_stack trav_stack);
void clear(Trav_stack *const trav_stack);

#endif
