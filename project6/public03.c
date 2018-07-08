#include <stdio.h>
#include <assert.h>
#include "graph.h"

/* CMSC 216, Fall 2017, Project #6
 * Public test 3 (public03.c)
 *
 * Tests the return value of add_vertex() when a new vertex is successfully
 * added, and when it's called on already-existing vertices.
 *
 * (c) Larry Herman, 2017.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main() {
  Graph graph;

  init_graph(&graph);

  /* add some vertices */
  assert(add_vertex(&graph, "koala"));
  assert(add_vertex(&graph, "parrot"));
  assert(add_vertex(&graph, "platypus"));

  /* now try to add them again */
  assert(!add_vertex(&graph, "koala"));
  assert(!add_vertex(&graph, "parrot"));
  assert(!add_vertex(&graph, "platypus"));

  printf("No assertion remains unsatisfied!\n");

  return 0;
}
