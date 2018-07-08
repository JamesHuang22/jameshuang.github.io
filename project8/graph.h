/* (c) Larry Herman, 2017.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

#if !defined(GRAPH_H)
#define GRAPH_H

#include "graph-datastructure.h"

void init_graph(Graph *graph);
int add_vertex(Graph *graph, const char new_vertex[]);
int num_vertices(Graph graph);
int has_vertex(Graph graph, const char name[]);
char **get_vertices(Graph graph);
int add_edge(Graph *graph, const char source[], const char dest[], int cost);
int get_edge_cost(Graph graph, const char source[], const char dest[]);
int num_neighbors(Graph graph, const char vertex[]);
char **get_neighbors(Graph graph, const char vertex[]);
void free_string_list(char **strings);
void clear_graph(Graph *graph);
int remove_edge(Graph *graph, const char source[], const char dest[]);
int remove_vertex(Graph *graph, const char vertex[]);

/* in the scope where an array is declared (and *only* in the scope where
 * it's declared), this expression will evaluate to the number of elements
 * in the array
 */
#define NUM_ELTS(arr) ((int) (sizeof(arr) / sizeof(arr[0])))

#endif
