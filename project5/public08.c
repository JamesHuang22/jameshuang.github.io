#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "student.h"

/* CMSC 216, Fall 2017, Project #5
 * Public test 2 (public02.c)
 *
 * Tests that long student names can be created and changed with change_name().
 *
 * (c) Larry Herman, 2017.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  Student *s, *t= new_student("Tricia", 64321, 7.5), *u;
  char long_name1[1001]= "", long_name2[1001]= "";
  int i;

  for (i= 0; i < 40; i++)
    strcat(long_name1, "Sophie");
  for (i= 0; i < 100; i++)
    strcat(long_name2, "Alessandra");

  s= new_student(long_name1, 11144, 6.5);
  u= new_student(long_name2, 88444, 8.5);

  assert(has_id(s, 11144));
  assert(get_id(s) == 11144);
  assert(has_name(s, long_name1));
  assert(get_shoe_size(s) == 6.5);

  assert(has_id(t, 64321));
  assert(get_id(t) == 64321);
  assert(has_name(t, "Tricia"));
  assert(get_shoe_size(t) == 7.5);

  assert(has_id(u, 88444));
  assert(get_id(u) == 88444);
  assert(has_name(u, long_name2));
  assert(get_shoe_size(u) == 8.5);

  /* reset long_name2 and store something else in it */
  strcpy(long_name2, "");
  for (i= 0; i < 200; i++)
    strcat(long_name2, "Jenna");

  change_name(t, long_name2);

  assert(has_id(t, 64321));
  assert(get_id(t) == 64321);
  assert(has_name(t, long_name2));
  assert(get_shoe_size(t) == 7.5);

  printf("The assertions were victorious!\n");

  return 0;
}
