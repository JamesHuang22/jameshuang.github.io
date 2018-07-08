#include <stdio.h>
#include <assert.h>
#include "graph.h"
#include "memory-checking.h"

/* CMSC 216, Fall 2017, Project #8
 * Public test 4 (public04.c)
 *
 * Tests that clear_graph() frees all of the memory of the graph, and has no
 * errors in the heap.
 *
 * (c) Larry Herman, 2017.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main() {
  Graph graph;
  char *vertices_to_add[]= {"koala", "parrot", "snake", "salamander",
                            "giraffe", "frog", "dog", "hedgehog"};
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

  /* now trash the whole thing */
  clear_graph(&graph);

  #if !defined(ENABLE_VALGRIND)
  check_heap();
  #endif

  /* if this is the only thing printed the heap must be valid, and there
   * must not have been any memory leaks
   */
  printf("Everything worked perfectly!\n");

  return 0;
}
