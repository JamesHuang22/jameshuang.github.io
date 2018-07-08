#include <string.h>
#include "compare-name-lists.h"

/* (c) Larry Herman, 2017.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

/* Takes two array of pointers to dynamically-allocated strings (pointers to
 * characters), which must end in NULL, and compares them, returning 1 if
 * they have the same number of elements and the same corresponding
 * elements, and 0 otherwise.  This just makes it easier to compare the
 * results of some tests against the expected results (tests that would be
 * calling get_vertices() and get_neighbors()).  Also returns 1 if both
 * parameters are NULL.
 */
int compare_name_lists(char **names, char **expected_names) {
  int i= 0, result= 0;  /* return 0 if one parameter (but not both) is NULL */

  if (names == NULL && expected_names == NULL)
    result= 1;
  else
    if (names != NULL && expected_names != NULL) {
      while (names[i] != NULL && expected_names[i] != NULL &&
             !strcmp(names[i], expected_names[i]))
        i++;

      /* all the strings must have been equal if we reached the end of both
         arrays at the same time */
      result= (names[i] == NULL && expected_names[i] == NULL);
    }
  
  return result;
}
