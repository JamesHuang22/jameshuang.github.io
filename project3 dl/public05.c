#include <stdio.h>
#include <assert.h>
#include "machine.h"

/* CMSC 216, Fall 2017, Project #3
 * Public test 5 (public05.c)
 *
 * Tests calling load_program() to load a program starting somewhere in the
 * middle of memory.
 *
 * (c) Larry Herman, 2017.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

#define PROGRAM_SIZE 8

int main() {
  Word memory[NUM_WORDS]= {0};
  Word program[PROGRAM_SIZE]= {0x0800014b, 0x2800016c, 0x500001ac, 0x7800016f,
                               0x400001e0, 0x480001a0, 0xa8000000, 0x980001af};
  int i;

  assert(load_program(memory, 200, program, PROGRAM_SIZE) == 1);

  /* go through all of memory to both check that the program was loaded into
     the right place, and in the process also verify that the rest of memory
     wasn't changed */
  for (i= 0; i < NUM_WORDS; i++)
    if (i >= 50 && i <= 50 + PROGRAM_SIZE)
      assert(memory[i] == program[i - 50]);
    else assert(memory[i] == 0);

  printf("Every assertion was completely successful!\n");

  return 0;
}
