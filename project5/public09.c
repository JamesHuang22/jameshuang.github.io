#include <stdio.h>
#include <assert.h>
#include "student.h"

/* CMSC 216, Fall 2017, Project #5
 * Public test 9 (public09.c)
 *
 * Tests passing in NULL to all of the name parameters (for all functions
 * that have a name parameter).
 *
 * (c) Larry Herman, 2017.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  Student *s= new_student("Hao", 11111, 8.0);
  Student *t= new_student(NULL, 88282, 10.0);

  /* should return 0, and by the way not crash */
  assert(!has_name(s, NULL));
  assert(has_name(s, "Hao"));

  /* should set the student's name to an empty string, and not crash */
  change_name(s, NULL);
  assert(has_name(s, ""));

  assert(has_name(t, ""));

  printf("The assertions were victorious!\n");

  return 0;
}
