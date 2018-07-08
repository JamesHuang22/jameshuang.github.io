#include <stdio.h>
#include <assert.h>
#include "machine.h"

/* CMSC 216, Fall 2017, Project #3
 * Public test 7 (public07.c)
 *
 * Tests load_program() with a program containing an instruction subject to
 * relocation.  Its fifth instruction is "branch 12", and the program is
 * loaded starting at address 20.
 *
 * (c) Larry Herman, 2017.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

#define PROGRAM_SIZE 8

int main() {
  Word memory[NUM_WORDS]= {0};
  Word program[PROGRAM_SIZE]= {0x0800014b, 0x180001ce, 0x2800016c, 0x3800020f,
                               0xa0003000, 0x580001ac, 0x6000020b, 0x6800016f};
  int i;

  assert(load_program(memory, 20, program, PROGRAM_SIZE) == 1);

  /* go through all of memory to both check that the program was loaded into
     the right place, and in the process also verify that the rest of memory
     wasn't changed */
  for (i= 0; i < NUM_WORDS; i++)
    if (i >= 5 && i <= 5 + PROGRAM_SIZE)
      /* all instructions except the fifth should be unchanged */
      if (i != 9)
        assert(memory[i] == program[i - 5]);
      else assert(memory[i] == 0xa0008000);  /* the relocated fifth instr. */
    else assert(memory[i] == 0);

  printf("Every assertion was completely successful!\n");

  return 0;
}
