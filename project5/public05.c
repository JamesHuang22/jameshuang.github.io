#include <stdio.h>
#include <assert.h>
#include "student.h"

/* CMSC 216, Fall 2017, Project #5
 * Public test 5 (public05.c)
 *
 * Tests that has_name() and has_id() return 0 when called with the
 * incorrect name and ID for a student.
 *
 * (c) Larry Herman, 2017.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  Student *s= new_student("Alex", 11144, 6.5);

  assert(!has_name(s, "Alexander"));
  assert(!has_id(s, 11114));

  printf("The assertions were victorious!\n");

  return 0;
}
