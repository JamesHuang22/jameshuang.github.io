#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "trav-stack.h"


int main() {
 Trav_stack trav_stack;
  char *element;
  init(&trav_stack);
  
  push(&trav_stack, "sdf");
  push(&trav_stack, "bsa");
  push(&trav_stack, "mgs");
  push(&trav_stack, "wer");
  push(&trav_stack, "bwe");
  push(&trav_stack, "mds");
 

  pop(&trav_stack);
  pop(&trav_stack);

  push(&trav_stack, "abc");
  down(&trav_stack);
  element= read(trav_stack);
 
  assert(strcmp(element,"wer") == 0);

  clear(&trav_stack);

  printf("All assertions were wildly successful!\n");

  return 0;
}


