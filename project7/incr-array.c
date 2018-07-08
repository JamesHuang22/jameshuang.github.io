#include "incr-array.h"

/* (c) Larry Herman, 2017.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

void incr_array(int a[], int size) {
  size--;
  while (size >= 0) {
    a[size]++;
    size--;
  }
}
