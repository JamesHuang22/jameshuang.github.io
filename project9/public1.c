#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "trav-stack.h"

/* CMSC 216, Fall 2017, Project #9
 * Public test 1 (public1.c)
 *
 * Tests the basic functionality of a few of the traversable stack
 * functions.
 *
 * (c) Larry Herman, 2017.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main() {
  Trav_stack trav_stack;
  char *element;

  init(&trav_stack);

  push(&trav_stack, "Kangaroo");
  push(&trav_stack, "Llama");
  push(&trav_stack, "Platypus");
  push(&trav_stack, "Giraffe");
  push(&trav_stack, "Parrot");

  element= read(trav_stack);
  assert(strcmp(element, "Parrot") == 0);
  free(element);

  down(&trav_stack);
  element= read(trav_stack);
  assert(strcmp(element, "Giraffe") == 0);
  free(element);

  clear(&trav_stack);

  printf("All assertions were wildly successful!\n");

  return 0;
}
