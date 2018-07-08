#include <stdio.h>
#include <assert.h>
#include "machine.h"

/* CMSC 216, Fall 2017, Project #3
 * Public test 9 (public09.c)
 *
 * Tests calling valid_instruction() with some valid instructions, and some
 * with invalid first register operands.
 *
 * (c) Larry Herman, 2017.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

#define PROGRAM_SIZE 10

int main() {
  Word program[PROGRAM_SIZE]= {0x0800014b, 0x1000028b, 0x180001ce, 0x280002ac,
                               0x3800020f, 0x500002cc, 0x7000020b, 0x780002ef,
                               0x400001e0, 0x48000300};
  int i;

  /* the instructions in the array alternate between valid and invalid */
  for (i= 0; i < PROGRAM_SIZE; i++)
    assert(valid_instruction(program[i]) == (i % 2 ? BADREG1 : VALID));

  printf("Every assertion was completely successful!\n");

  return 0;
}
