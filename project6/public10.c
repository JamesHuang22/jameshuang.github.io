#include <stdio.h>
#include <assert.h>
#include "graph.h"

/* CMSC 216, Fall 2017, Project #6
 * Public test 10 (public10.c)
 *
 * Creates a larger graph and calls some of the functions on it.
 *
 * (c) Larry Herman, 2017.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

#define NUM_EDGES 50

int main() {
  Graph graph;
  char name[2]= "";
  char ch;
  int i;
  const char *sources[NUM_EDGES]= {
    "A", "A", "B", "B", "B", "D", "D", "D", "D", "E",
    "F", "G", "G", "G", "G", "H", "H", "I", "J", "J",
    "K", "K", "K", "K", "K", "L", "M", "N", "O", "O",
    "O", "O", "O", "O", "P", "Q", "S", "T", "T", "U",
    "U", "V", "W", "X", "Y", "Z", "Z", "Z", "Z", "Z"
  };
  const char *destinations[NUM_EDGES]= {
    "C", "M", "S", "C", "I", "S", "K", "E", "W", "L",
    "I", "W", "O", "N", "D", "E", "R", "W", "H", "O",
    "C", "A", "N", "F", "G", "U", "R", "E", "T", "H",
    "I", "S", "O", "U", "T", "A", "N", "D", "W", "H",
    "O", "W", "I", "L", "L", "N", "O", "T", "H", "M",
  };
  int costs[NUM_EDGES]= {
    84, 26,  2, 22,  1, 58, 49, 59, 42, 81, 
    57, 94, 34, 49,  9,  3, 27,  6, 41, 53, 
    78, 33, 41, 72, 82, 62, 36, 98, 58, 44, 
    73, 55, 36, 22, 55, 65, 57, 34, 46, 50, 
    35, 96, 13, 57, 96, 69, 46, 51, 10, 23
  };
  int expected_neighbors[26]= {
    2, 3, 0, 4, 1, 1, 4, 2, 1, 2, 5, 1, 1,
    1, 6, 1, 1, 0, 1, 2, 2, 1, 1, 1, 1, 5
  };

  init_graph(&graph);

  /* add 26 vertices */
  for (ch= 'A'; ch <= 'Z'; ch++) {
    name[0]= ch;
    add_vertex(&graph, name);
  }

  /* make sure they're there */
  assert(num_vertices(graph) == 26);

  /* add 50 edges */
  for (i= 0; i < NUM_EDGES; i++)
    assert(add_edge(&graph, sources[i], destinations[i], costs[i]));

  /* check the edges */
  for (i= 0; i < NUM_EDGES; i++)
    assert(get_edge_cost(graph, sources[i], destinations[i]) == costs[i]);

  /* check the number of neighbors that each vertex has */
  for (ch= 'A'; ch <= 'Z'; ch++) {
    name[0]= ch;
    assert(num_neighbors(graph, name) == expected_neighbors[ch - 'A']);
  }

  printf("No assertion remains unsatisfied!\n");

  return 0;
}
