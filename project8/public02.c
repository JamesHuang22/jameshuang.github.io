#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "graph.h"
#include "memory-checking.h"

/* CMSC 216, Fall 2017, Project #8
 * Public test 2 (public02.c)
 *
 * Tests calling free_string_list() on an array of dynamically allocated
 * strings.  Ensures that all memory is properly freed.
 *
 * (c) Larry Herman, 2017.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main() {
  char *some_strings[]= {"koala", "giraffe", "parrot", "zebra", "hedgehog",
                         "hippopotamus", "rhinoceros", "dog", "frog"};
  char **animals;
  int i;

  #if !defined(ENABLE_VALGRIND)
  setup_memory_checking();
  #endif

  /* some_strings is not dynamically allocated so we can't call
   * free_string_list() on it; we will make a dynamically allocated copy of
   * what's in it to test the function with
   */
  animals= calloc(1 + NUM_ELTS(some_strings), sizeof(*animals));

  if (animals != NULL) {

    for (i= 0; i < NUM_ELTS(some_strings); i++) {
      animals[i]= malloc(strlen(some_strings[i]) + 1);
      if (animals[i] != NULL)
        strcpy(animals[i], some_strings[i]);
    }

    /* ensure the last element is NULL */
    animals[i]= NULL;

    /* now release everything that was allocated */
    free_string_list(animals);

  }

  #if !defined(ENABLE_VALGRIND)
  check_heap();
  #endif

  printf("Everything worked perfectly!\n");

  return 0;
}
