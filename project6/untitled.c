#include <stdio.h>
#include <assert.h>
#include "graph.h"
#include "compare-name-lists.h"


int main() {
  Graph graph;
  char *all_neighbor[]= {"elephant", "giraffe", "hedgehog", "parrot", NULL};

  init_graph(&graph);

  /* add some vertices */
  add_vertex(&graph, "hedgehog");
  add_vertex(&graph, "kangaroo");
  add_vertex(&graph, "parrot");
  add_vertex(&graph, "elephant");
  add_vertex(&graph, "giraffe");

/* add some edges between them */
  add_edge(&graph, "kangaroo", "hedgehog", 8);
  add_edge(&graph, "kangaroo", "parrot", 2);
  add_edge(&graph, "kangaroo", "elephant", 6);
  add_edge(&graph, "kangaroo", "giraffe", 9);

  
  assert(compare_name_lists(get_neighbors(graph,"kangaroo"), all_neighbor));

  printf("No assertion remains unsatisfied!\n");

  return 0;
}
