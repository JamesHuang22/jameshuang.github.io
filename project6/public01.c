#include <stdio.h>
#include <assert.h>
#include "graph.h"

/* CMSC 216, Fall 2017, Project #6
 * Public test 1 (public01.c)
 *
 * Tests initializing a graph and calling num_vertices() before any vertices
 * have been added, then after some vertices have been added.
 *
 * (c) Larry Herman, 2017.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main() {
  Graph graph;

  init_graph(&graph);

  /* the graph should be completely devoid of vertices */
  assert(num_vertices(graph) == 0);

  /* let's address that situation now */
  add_vertex(&graph, "hedgehog");
  add_vertex(&graph, "koala");
  add_vertex(&graph, "parrot");
  add_vertex(&graph, "kangaroo");
  add_vertex(&graph, "elephant");
  add_vertex(&graph, "naked mole rat");

  /* how many vertices now? */
  assert(num_vertices(graph) == 6);

  printf("No assertion remains unsatisfied!\n");

  return 0;
}
