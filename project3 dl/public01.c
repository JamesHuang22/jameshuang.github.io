#include <stdio.h>
#include "machine.h"

/* CMSC 216, Fall 2017, Project #3
 * Public test 1 (public01.c)
 *
 * Tests print_instruction() with some no-operand and one-operand
 * instructions.
 *
 * (c) Larry Herman, 2017.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main() {
  print_instruction(0x0800014b);
  print_instruction(0x180001ce);
  print_instruction(0x2800016c);
  print_instruction(0x3800020f);
  print_instruction(0x500001ac);
  print_instruction(0x7000020b);
  print_instruction(0x7800016f);

  return 0;
}
