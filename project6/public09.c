#include <stdio.h>
#include <assert.h>
#include "graph.h"

/* CMSC 216, Fall 2017, Project #6
 * Public test 9 (public09.c)
 *
 * Tests calling num_neighbors() on some vertices that have neighbors in a
 * graph.
 *
 * (c) Larry Herman, 2017.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main() {
  Graph graph;

  init_graph(&graph);

  /* add some vertices */
  add_vertex(&graph, "parrot");
  add_vertex(&graph, "kangaroo");
  add_vertex(&graph, "platypus");
  add_vertex(&graph, "giraffe");
  add_vertex(&graph, "koala");
  add_vertex(&graph, "hedgehog");

  /* add some edges between them */
  add_edge(&graph, "hedgehog", "kangaroo", 8);
  add_edge(&graph, "koala", "parrot", 2);
  add_edge(&graph, "giraffe", "platypus", 6);
  add_edge(&graph, "koala", "giraffe", 10);
  add_edge(&graph, "hedgehog", "parrot", 1);
  add_edge(&graph, "platypus", "koala", 7);
  add_edge(&graph, "hedgehog", "hedgehog", 9);

  /* test the number of neighbors of three of the vertices */
  assert(num_neighbors(graph, "giraffe") == 1);
  assert(num_neighbors(graph, "koala") == 2);
  assert(num_neighbors(graph, "hedgehog") == 3);

  printf("No assertion remains unsatisfied!\n");

  return 0;
}
