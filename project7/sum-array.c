#include "sum-array.h"

/* (c) Larry Herman, 2017.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int sum_array(int arr[], int size) {
  int i, sum= 0;

  for (i= 0; i < size; i++)
    sum += arr[i];

  return sum;
}

