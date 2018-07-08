#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "graph.h"

/* CMSC 216, Fall 2017, Project #8
 * Public test 8 (public08.c)
 *
 * Tests using remove_vertex() to remove all of the vertices from a graph.
 * Note that this test intentionally does not free any memory, so it will
 * have memory leaks.  (It is only testing the functionality of removing
 * vertices, not whether memory leaks occur in the process.)
 *
 * (c) Larry Herman, 2017.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main() {
  Graph graph;
  char *vertices_to_add[]= {"koala", "giraffe", "parrot", "zebra", "hedgehog",
                            "dog", "frog"};
  int i;

  init_graph(&graph);

  /* add some vertices */
  for (i= 0; i < NUM_ELTS(vertices_to_add); i++)
    add_vertex(&graph, vertices_to_add[i]);

  /* now remove all of the vertices */
  for (i= 0; i < NUM_ELTS(vertices_to_add); i++)
    remove_vertex(&graph, vertices_to_add[i]);

  assert(num_vertices(graph) == 0);

  /* now release all memory */
  clear_graph(&graph);

  printf("Everything worked perfectly!\n");

  return 0;
}
