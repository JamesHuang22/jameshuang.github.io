#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "graph.h"
#include "compare-name-lists.h"

/* CMSC 216, Fall 2017, Project #8
 * Public test 7 (public07.c)
 *
 * Tests calling remove_vertex(), and ensures that the vertex is properly
 * removed.  Note that this test intentionally does not free any memory, so
 * it will have memory leaks.  (It is only testing the functionality of
 * remove_vertex() in removing vertices, not whether memory leaks occur in
 * the process.)
 *
 * (c) Larry Herman, 2017.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main() {
  Graph graph;
  char *vertices_to_add[]= {"koala", "quokka", "parrot", "zebra", "hedgehog",
                            "dog", "frog"};
  char *expected_results[]= {"dog", "frog", "hedgehog", "parrot", "quokka",
                             "zebra", NULL};
  char **names;
  int i;

  init_graph(&graph);

  /* add some vertices */
  for (i= 0; i < NUM_ELTS(vertices_to_add); i++)
    add_vertex(&graph, vertices_to_add[i]);

  /* now remove one of the vertices */
  remove_vertex(&graph, "koala");

  names= get_vertices(graph);

  /* check the vertices against the results that we expect to be returned */
  compare_name_lists(names, expected_results);

  clear_graph(&graph);

  printf("Everything worked perfectly!\n");

  return 0;
}
