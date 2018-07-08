#include <stdio.h>
#include <assert.h>
#include "student.h"

/* CMSC 216, Fall 2017, Project #5
 * Public test 6 (public06.c)
 *
 * Tests the functions simulating a slightly more realistic scenario- an
 * array of multiple students is created, and the functions are used to
 * search for and modify elements of the array.
 *
 * (c) Larry Herman, 2017.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

#define SZ 10

int main(void) {
  Student *roster[SZ];
  int i;

  roster[0]= new_student("Sally", 18491, 7.5);
  roster[1]= new_student("Lucas", 81747, 11);
  roster[2]= new_student("David", 89747, 11.5);
  roster[3]= new_student("Chloe", 88195, 8.0);
  roster[4]= new_student("Jose", 11928, 10.0);
  roster[5]= new_student("Madison", 76644, 8.5);
  roster[6]= new_student("Benjamin", 80875, 9.0);
  roster[7]= new_student("Mia", 76647, 9.5);
  roster[8]= new_student("Ernest", 99974, 10.5);
  roster[9]= new_student("Kendra", 66331, 8.5);

  i= 0;
  while (i < 10 && !has_name(roster[i], "Jose"))
    i++;
  assert(i == 4);

  i= 0;
  while (i < 10 && !has_name(roster[i], "Kendra"))
    i++;
  assert(i == 9);

  i= 0;
  while (i < 10 && !has_name(roster[i], "Oscar"))
    i++;
  assert(i == 10);

  i= 0;
  while (i < 10 && !has_id(roster[i], 76644))
    i++;
  assert(i == 5);

  i= 0;
  while (i < 10 && !has_id(roster[i], 66331))
    i++;
  assert(i == 9);

  i= 0;
  while (i < 10 && !has_id(roster[i], 99999))
    i++;
  assert(i == 10);

  i= 0;
  while (i < 10 && !has_name(roster[i], "Chloe"))
    i++;
  change_name(roster[i], "Khloe");
  change_shoe_size(roster[i], 9.0);
  assert(has_id(roster[i], 88195));
  assert(get_id(roster[i]) == 88195);
  assert(get_shoe_size(roster[i]) == 9.0);

  i= 0;
  while (i < 10 && !has_name(roster[i], "Khloe"))
    i++;
  assert(i == 3);

  i= 0;
  while (i < 10 && !has_name(roster[i], "Chloe"))
    i++;
  assert(i == 10);

  printf("The assertions were victorious!\n");

  return 0;
}
