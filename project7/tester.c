#include <stdio.h>
#include "fill-array.h"
#include "incr-array.h"
#include "sum-array.h"

/* (c) Larry Herman, 2017.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  int arr[10];

  fill_array(arr, 0, 9, 2);
  printf("%d\n", sum_array(arr, 10));

  incr_array(arr, 10);
  printf("%d\n", sum_array(arr, 10));

  return 0;
}
