#include <stdio.h>
#include "machine.h"

/* CMSC 216, Fall 2017, Project #3
 * Public test 3 (public03.c)
 *
 * Tests print_instruction() with some load and store instructions, as well
 * as a move instruction.
 *
 * (c) Larry Herman, 2017.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main() {
  print_instruction(0x804401c0);
  print_instruction(0x882001e0);
  print_instruction(0x90480160);
  print_instruction(0x980001af);

  return 0;
}
