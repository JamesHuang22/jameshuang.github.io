#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "graph.h"
#include "compare-name-lists.h"
#include "memory-checking.h"

/* CMSC 216, Fall 2017, Project #8
 * Public test 3 (public03.c)
 *
 * Tests calling free_string_list() on the array of vertices returned by
 * get_vertices(), to ensure that all of the memory is properly freed and *
 * there are no errors in the heap.
 *
 * (c) Larry Herman, 2017.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main() {
  Graph graph;
  char *vertices_to_add[]= {"koala", "parrot", "snake", "salamander",
                            "giraffe", "frog", "dog", "hedgehog"};
  char *names_in_order[]= {"dog", "frog", "giraffe", "hedgehog", "koala",
                           "parrot",  "salamander", "snake", NULL};
  char **names;
  int i;

  #if !defined(ENABLE_VALGRIND)
  setup_memory_checking();
  #endif

  init_graph(&graph);

  /* add some vertices */
  for (i= 0; i < NUM_ELTS(vertices_to_add); i++)
    add_vertex(&graph, vertices_to_add[i]);

  /* check that the vertices were all added */
  assert(num_vertices(graph) == 8);

  /* get the vertex names */
  names= get_vertices(graph);

  /* now check them; note they must be in alphabetical order */
  assert(compare_name_lists(names, names_in_order));

  /* free the array returned by get_vertices() */
  free_string_list(names);

  /* now check that the graph still has the same vertices, by calling it
     again */
  i= 0;
  names= get_vertices(graph);
  while (names[i] != NULL) {
    assert(!strcmp(names[i], names_in_order[i]));
    i++;
  }

  /* free the second array returned by get_vertices() */
  free_string_list(names);

  /* and trash the whole graph */
  clear_graph(&graph);

  #if !defined(ENABLE_VALGRIND)
  check_heap();
  #endif

  printf("Everything worked perfectly!\n");

  return 0;
}
