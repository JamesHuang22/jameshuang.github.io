#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "graph.h"
#include "compare-name-lists.h"
#include "memory-checking.h"

/* CMSC 216, Fall 2017, Project #8
 * Public test 10 (public10.c)
 *
 * Tests that there are no memory leaks or errors in the heap after some
 * vertices and edges are removed from a graph, then new ones are added.
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
  char *new_edges_from[]= {"chicken", "chicken", "elephant", "elephant",
                           "hippopotamus", "hippopotamus",
                           "hippopotamus", "cow", "cow", "goat", "goat",
                           "mule", "mule", "mule"};
  char *new_edges_to[]= {"elephant", "turkey", "hippopotamus", "mule",
                         "cow", "horse", "goat", "horse", "elephant",
                         "horse", "lamb", "lamb", "hippopotamus",
                         "elephant"};
  char *final_vertices[]= {"chicken", "cow", "elephant", "goat",
                           "hippopotamus", "horse", "lamb", "mule", "turkey",
                           NULL};
  char *final_neighbors[][9]= {
    /* neighbors of chicken */
    {"cow", "elephant", "lamb", "mule", "turkey", NULL},
    /* neighbors of cow */
    {"chicken", "elephant", "horse", "turkey", NULL},
    /* neighbors of elephant */
    {"hippopotamus", "mule", NULL},
    /* neighbors of goat */
    {"cow", "horse", "lamb", "mule", "turkey", NULL},
    /* neighbors of hippopotamus */
    {"cow", "goat", "horse", NULL},
    /* neighbors of horse */
    {"turkey", NULL},
    /* neighbors of lamb */
    {"chicken", "goat", "horse", "lamb", "mule", "turkey", NULL},
    /* neighbors of mule */
    {"cow", "elephant", "hippopotamus", "horse", "lamb", "turkey", NULL},
    /* neighbors of turkey */
    {"cow", NULL}
  };
  char **names, **names2;
  int i;

  #if !defined(ENABLE_VALGRIND)
  setup_memory_checking();
  #endif

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

  /* remove some vertices */
  remove_vertex(&graph, "donkey");
  remove_vertex(&graph, "goose");

  /* now add some new vertices */
  add_vertex(&graph, "elephant");
  add_vertex(&graph, "hippopotamus");

  /* now add some new edges */
  for (i= 0; i < NUM_ELTS(new_edges_from); i++)
    add_edge(&graph, new_edges_from[i], new_edges_to[i], i + 20);

  /* now check the final vertices against the results that we expect */
  assert(num_vertices(graph) == 9);
  names= get_vertices(graph);
  assert(compare_name_lists(names, final_vertices));

  /* now check the final neighbors of all vertices */
  i= 0;
  while (names[i] != NULL) {
    names2= get_neighbors(graph, names[i]);
    assert(compare_name_lists(names2, final_neighbors[i++]));
    free_string_list(names2);
  }

  /* now clean up after ourselves */
  free_string_list(names);
  clear_graph(&graph);

  #if !defined(ENABLE_VALGRIND)
  check_heap();
  #endif

  printf("Everything worked perfectly!\n");

  return 0;
}
