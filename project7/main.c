#include <stdio.h>
#include "fill-array.h"
#include "compare-arrays.h"

/* (c) Larry Herman, 2017.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  int arr1[10];
  int arr2[10]= {216, 216, 216, 216, 216, 216, 216, 216, 216, 216};

  fill_array(arr1, 0, 3, 250);
  printf("%d\n", compare_arrays(arr1, arr2, 10));

  fill_array(arr1, 0, 9, 216);
  printf("%d\n", compare_arrays(arr1, arr2, 10));

  return 0;
}
