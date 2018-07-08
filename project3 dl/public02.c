#include <stdio.h>
#include "machine.h"

/* CMSC 216, Fall 2017, Project #3
 * Public test 2 (public02.c)
 *
 * Tests print_instruction() with some two-operand instructions.
 *
 * (c) Larry Herman, 2017.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main() {
  print_instruction(0x400001e0);
  print_instruction(0x480001a0);
  print_instruction(0xa0036000);
  print_instruction(0xa8000000);
  print_instruction(0x00000000);

  return 0;
}
