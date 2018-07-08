#include <stdio.h>
#include <assert.h>
#include "student.h"

/* CMSC 216, Fall 2017, Project #5
 * Public test 7 (public07.c)
 *
 * Tests copy_student().
 *
 * (c) Larry Herman, 2017.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  Student *s= new_student("Tricia", 11144, 6.5);
  Student *t= new_student("Sophie", 64321, 7.5);

  copy_student(t, s);

  assert(has_id(s, 11144));
  assert(get_id(s) == 11144);
  assert(has_name(s, "Tricia"));
  assert(get_shoe_size(s) == 6.5);

  assert(has_id(t, 11144));
  assert(get_id(t) == 11144);
  assert(has_name(t, "Tricia"));
  assert(get_shoe_size(t) == 6.5);

  printf("The assertions were victorious!\n");

  return 0;
}
