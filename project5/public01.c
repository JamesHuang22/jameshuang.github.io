#include <stdio.h>
#include <assert.h>
#include "student.h"

/* CMSC 216, Fall 2017, Project #5
 * Public test 1 (public01.c)
 *
 * Tests calling new_student() and checking that the student's data was
 * stored correctly.
 *
 * (c) Larry Herman, 2017.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  Student *s= new_student("Tricia", 11144, 6.5);

  assert(has_id(s, 11144));
  assert(get_id(s) == 11144);
  assert(has_name(s, "Tricia"));
  assert(get_shoe_size(s) == 6.5);

  printf("The assertions were victorious!\n");

  return 0;
}
