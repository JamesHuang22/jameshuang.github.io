#include <stdio.h>
#include <assert.h>
#include "machine.h"

/* CMSC 216, Fall 2017, Project #3
 * Public test 6 (public06.c)
 *
 * Tests calling load_program() to load a program into the entire memory, to
 * see if there are any off-by-1 errors in this case.
 *
 * (c) Larry Herman, 2017.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main() {
  Word memory[NUM_WORDS]= {0};
  Word program[NUM_WORDS];
  int i;

  /* fill up the entire program with the same instruction */
  for (i= 0; i < NUM_WORDS; i++)
    program[i]= 0x3800020f;

  assert(load_program(memory, 0, program, NUM_WORDS) == 1);

  /* now check that all of memory contains that instruction */
  for (i= 0; i < NUM_WORDS; i++)
    assert(memory[i] == 0x3800020f);

  printf("Every assertion was completely successful!\n");

  return 0;
}
