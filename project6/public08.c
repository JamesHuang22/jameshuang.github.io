#include <stdio.h>
#include <assert.h>
#include "graph.h"

/* CMSC 216, Fall 2017, Project #6
 * Public test 8 (public08.c)
 *
 * Tests calling add_vertex() with a NULL vertex name.
 *
 * (c) Larry Herman, 2017.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main() {
  Graph graph;

  init_graph(&graph);

  /* add some vertices, but the fourth one has a NULL name */
  add_vertex(&graph, "hedgehog");
  add_vertex(&graph, "koala");
  add_vertex(&graph, "platypus");
  add_vertex(&graph, NULL);  /* should have no effect, but not crash */
  add_vertex(&graph, "parrot");
  add_vertex(&graph, "giraffe");

  /* test that all of the other add_vertex() calls worked fine, and the
     fourth one was just ignored and had no effect */
  assert(num_vertices(graph) == 5);
  assert(has_vertex(graph, "hedgehog"));
  assert(has_vertex(graph, "koala"));
  assert(has_vertex(graph, "platypus"));
  assert(has_vertex(graph, "parrot"));
  assert(has_vertex(graph, "giraffe"));

  printf("No assertion remains unsatisfied!\n");

  return 0;
}
