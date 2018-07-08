#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "graph.h"
#include "compare-name-lists.h"

/* CMSC 216, Fall 2017, Project #8
 * Public test 9 (public09.c)
 *
 * Tests removing a vertex and several edges from a graph.  Note that this
 * test intentionally does not free any memory, so it will have memory
 * leaks.  (It is only testing the functionality of removing vertices and
 * edges, not whether memory leaks occur in the process.)
 *
 * (c) Larry Herman, 2017.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main() {
  Graph graph;
  char *vertices[]= {"horse", "cow", "chicken", "turkey", "lamb", "goat",
                     "donkey", "goose", "mule"};
  char *from[]= {"cow", "cow", "cow", "cow", 
                 "lamb", "lamb", "lamb", "lamb", "lamb", "lamb", "lamb",
                 "mule", "mule", "mule", "mule",
                 "donkey", "donkey", "donkey", "donkey",
                 "turkey",
                 "horse", "horse",
                 "chicken", "chicken", "chicken", "chicken",
                 "goat", "goat", "goat", "goat", "goat"};
  char *to[]= {"lamb", "turkey", "chicken", "goat",
               "mule", "turkey", "goat", "horse", "lamb", "chicken",
               "goose",
               "turkey", "horse", "goat", "cow",
               "mule", "goose", "cow", "chicken", 
               "cow",
               "goose", "turkey",
               "lamb", "cow", "horse", "mule",
               "cow", "goose", "turkey", "horse", "mule"};
  const int costs[]= {9, 3, 4, 10, 4, 15, 3, 18, 7, 5, 21, 1, 12, 5, 30, 17,
                      14, 21, 8, 29, 15, 27, 3, 1, 5, 1, 8, 15, 26, 10, 9};
  char *remaining_vertices[]= {"chicken", "cow", "goat", "goose", "horse",
                               "lamb", "mule", "turkey", NULL};
  char **names;
  int i;

  init_graph(&graph);

  /* add some vertices */
  for (i= 0; i < NUM_ELTS(vertices); i++)
    add_vertex(&graph, vertices[i]);

  /* add some edges */
  for (i= 0; i < NUM_ELTS(from); i++)
    add_edge(&graph, from[i], to[i], costs[i]);

  /* remove some edges */
  remove_edge(&graph, "chicken", "horse");
  remove_edge(&graph, "cow", "goat");
  remove_edge(&graph, "cow", "lamb");
  remove_edge(&graph, "goat", "horse");
  remove_edge(&graph, "mule", "goat");

  /* remove a vertex */
  remove_vertex(&graph, "donkey");

  /* check the remaining vertices against the results that we expect */
  assert(num_vertices(graph) == 8);
  names= get_vertices(graph);
  compare_name_lists(names, remaining_vertices);

  /* check the current edges of the vertices that we removed some edges from */
  assert(num_neighbors(graph, "chicken") == 3);
  assert(num_neighbors(graph, "cow") == 2);
  assert(num_neighbors(graph, "goat") == 4);
  assert(num_neighbors(graph, "mule") == 3);

  /* now clean up after ourselves */
  free_string_list(names);
  clear_graph(&graph);

  printf("Everything worked perfectly!\n");

  return 0;
}
