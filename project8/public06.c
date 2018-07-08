#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "graph.h"
#include "compare-name-lists.h"

/* CMSC 216, Fall 2017, Project #8
 * Public test 6 (public06.c)
 *
 * Tests calling remove_edge(), and ensures that the edge is properly
 * removed.  Note that this test intentionally does not free any memory, so
 * it will have memory leaks.  (It is only testing the functionality of
 * remove_edge() in removing edges, not whether memory leaks occur in the
 * process.)
 *
 * (c) Larry Herman, 2017.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main() {
  Graph graph;
  char *vertices_to_add[]= {"koala", "parrot", "snake", "salamander",
                            "giraffe", "frog", "dog", "hedgehog"};
  char *from[]= {"dog", "frog", "hedgehog", "hedgehog", "hedgehog", "parrot",
                 "platypus", "giraffe", "snake", "snake"};
  char *to[]= {"frog", "dog", "dog", "salamander", "koala", "koala",
               "salamander", "frog", "salamander", "parrot"};
  const int costs[]= {2, 5, 9, 8, 7, 3, 1, 2, 10, 6};
  char *expected_results1[]= {"dog", "koala", "salamander", NULL};
  char *expected_results2[]= {"dog", "salamander", NULL};
  char **names;
  int i;

  init_graph(&graph);

  /* add some vertices */
  for (i= 0; i < NUM_ELTS(vertices_to_add); i++)
    add_vertex(&graph, vertices_to_add[i]);

  /* add some edges */
  for (i= 0; i < NUM_ELTS(from); i++)
    add_edge(&graph, from[i], to[i], costs[i]);

  /* check hedgehog's neighbors */
  names= get_neighbors(graph, "hedgehog");
  assert(compare_name_lists(names, expected_results1));

  /* now remove one of hedgehog's neighbors */
  remove_edge(&graph, "hedgehog", "koala");

  names= get_neighbors(graph, "hedgehog");

  /* check the neighbors against the results that we expect to be returned */
  assert(compare_name_lists(names, expected_results2));

  printf("Everything worked perfectly!\n");

  return 0;
}
