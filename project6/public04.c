#include <stdio.h>
#include <assert.h>
#include "graph.h"
#include "compare-name-lists.h"

/* CMSC 216, Fall 2017, Project #6
 * Public test 4 (public04.c)
 *
 * Tests calling get_vertices() on a graph that has some vertices.
 *
 * (c) Larry Herman, 2017.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main() {
  Graph graph;
  char *all_vertices[]= {"elephant", "hedgehog", "kangaroo", "koala",
                         "naked mole rat", "parrot", NULL};

  init_graph(&graph);

  /* add some vertices */
  add_vertex(&graph, "hedgehog");
  add_vertex(&graph, "koala");
  add_vertex(&graph, "parrot");
  add_vertex(&graph, "kangaroo");
  add_vertex(&graph, "elephant");
  add_vertex(&graph, "naked mole rat");

  /* uses helper function to ensure that the list of names returned by
     get_vertices() equals the expected list declared above */
  assert(compare_name_lists(get_vertices(graph), all_vertices));

  printf("No assertion remains unsatisfied!\n");

  return 0;
}
