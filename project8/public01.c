#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "graph.h"
#include "compare-name-lists.h"

/* CMSC 216, Fall 2017, Project #8
 * Public test 1 (public01.c)
 *
 * Tests calling get_neighbors() on a vertex with several neighbors.
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
  char *expected_results[]= {"dog", "koala", "salamander", NULL};
  char **names;
  int i;

  init_graph(&graph);

  /* add some vertices */
  for (i= 0; i < NUM_ELTS(vertices_to_add); i++)
    add_vertex(&graph, vertices_to_add[i]);

  /* add some edges */
  for (i= 0; i < NUM_ELTS(from); i++)
    add_edge(&graph, from[i], to[i], costs[i]);

  names= get_neighbors(graph, "hedgehog");

  /* check the neighbors against the results that we expect to be returned */
  assert(compare_name_lists(names, expected_results));

  /* now clean up after ourselves */
  free_string_list(names);
  clear_graph(&graph);

  printf("Everything worked perfectly!\n");

  return 0;
}
