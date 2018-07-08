#include <stdio.h>
#include <assert.h>
#include "graph.h"

/* CMSC 216, Fall 2017, Project #6
 * Public test 2 (public02.c)
 *
 * Tests initializing a graph and calling num_vertices() before any vertices
 * have been added, then on some vertices that have been added to the graph,
 * as well as some nonexistent vertices.
 *
 * (c) Larry Herman, 2017.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main() {
  Graph graph;

  init_graph(&graph);

  /* add some vertices */
  add_vertex(&graph, "hedgehog");
  add_vertex(&graph, "koala");
  add_vertex(&graph, "parrot");
  add_vertex(&graph, "kangaroo");
  add_vertex(&graph, "elephant");
  add_vertex(&graph, "naked mole rat");

  /* check that these are existent vertices */
  assert(has_vertex(graph, "hedgehog"));
  assert(has_vertex(graph, "parrot"));
  assert(has_vertex(graph, "elephant"));
  assert(has_vertex(graph, "naked mole rat"));

  /* check that these are nonexistent vertices */
  assert(!has_vertex(graph, "deer"));
  assert(!has_vertex(graph, "rabbit"));

  printf("No assertion remains unsatisfied!\n");

  return 0;
}
