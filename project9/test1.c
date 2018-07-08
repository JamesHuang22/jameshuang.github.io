#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "trav-stack.h"


int main() {
  Trav_stack trav_stack;
 
  init(&trav_stack);

  push(&trav_stack, "Kangaroo");
  push(&trav_stack, "Llama");
  push(&trav_stack, "Platypus");
  push(&trav_stack, "Giraffe");
  push(&trav_stack, "Parrot");

  assert(size(trav_stack) == 5);

  
  clear(&trav_stack);

  printf("All assertions were wildly successful!\n");

  return 0;
}

