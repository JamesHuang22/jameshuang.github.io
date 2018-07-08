#include <stdio.h>
#include <assert.h>
#include "graph.h"

/* CMSC 216, Fall 2017, Project #6
 * Public test 6 (public06.c)
 *
 * Tests the return value of add_edge() with both positive and negative
 * weight edges.
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
  add_vertex(&graph, "platypus");
  add_vertex(&graph, "kangaroo");
  add_vertex(&graph, "parrot");
  add_vertex(&graph, "giraffe");

  /* call add_edge() and don't even test for the presence or absence of the
     edges later, just test add_edge()'s return value */

  /* these two edges are valid */
  assert(add_edge(&graph, "hedgehog", "kangaroo", 8));
  assert(add_edge(&graph, "koala", "parrot", 2));
  
  /* this edges is not valid */
  assert(add_edge(&graph, "giraffe", "platypus", -10) == 0);
 
  printf("No assertion remains unsatisfied!\n");

  return 0;
}
