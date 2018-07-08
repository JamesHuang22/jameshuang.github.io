#include <stdio.h>
#include <assert.h>
#include "graph.h"

/* CMSC 216, Fall 2017, Project #6
 * Public test 7 (public07.c)
 *
 * Tests calling get_edge_cost() on nonexistent edges.
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

  /* none of these edges exist */
  assert(get_edge_cost(graph, "koala", "hedgehog") == -1);
  assert(get_edge_cost(graph, "hedgehog", "frog") == -1);
  assert(get_edge_cost(graph, "frog", "dog") == -1);
  assert(get_edge_cost(graph, "lion", "tiger") == -1);

  printf("No assertion remains unsatisfied!\n");

  return 0;
}
