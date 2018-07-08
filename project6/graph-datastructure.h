#include <stdio.h>
#include <stdlib.h>
#ifndef graph_datastructure_h
#define graph_datastructure_h

typedef struct edge
{	
	int cost;
	struct vertex* dest_vertex;
    struct edge* next;
}Edge;

typedef struct vertex
{
	char* vertex_name;
	Edge* edge;
	struct vertex* next;
}Vertex;

typedef struct graph{
	int size;
	Vertex* root;
}Graph;

#endif 