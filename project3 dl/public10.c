#include <stdio.h>
#include <assert.h>
#include "machine.h"

/* CMSC 216, Fall 2017, Project #3
 * Public test 10 (public10.c)
 *
 * Calls calling decode_instruction() and load_program() with some NULL
 * arguments.
 *
 * (c) Larry Herman, 2017.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main() {
  Word memory[NUM_WORDS]= {0};
  unsigned short opcode= 0, register1= 0;
  unsigned int addr= 0;

  assert(decode_instruction(0x0800014b, &opcode, &addr, &register1,
                            NULL) == 0);

  /* ensure nothing changed */
  assert(opcode == 0);
  assert(addr == 0);
  assert(register1 == 0);

  assert(load_program(memory, 0, NULL, 1) == 0);

  printf("Every assertion was completely successful!\n");

  return 0;
}
