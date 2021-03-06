/* NAME: ZHIYU HUANG
** UID: 114622518
** Section: 0306
*/
#include <stdio.h>
#include "graph.h"
#include <string.h>
/*
** In this project, Based on the program of project 6, some new funcitons are
** added and the program will free any allocated memory when it is no
** longer needed
*/

/* Initialize the graph parameter by set the root vertex to be NULL and 
** the size of the graph to 0.
*/
void init_graph(Graph *graph){
  graph->root = NULL;
  graph->size = 0;
}

/* add a new vertex to the graph parameter, also copy the vertex
** name into a newly-created dymically-allocated array that sufficient to 
** store the name
*/
int add_vertex(Graph *graph, const char new_vertex[]){
  Vertex *curr = NULL, *prev = NULL, *new_ver = NULL;
  if(graph == NULL || new_vertex == NULL)
    return 0;
  else{
    curr = graph->root;
    new_ver = malloc(sizeof(Vertex));
    if(new_ver != NULL){
      new_ver->vertex_name = malloc(sizeof(char)*(strlen(new_vertex) + 1));
      strcpy(new_ver->vertex_name,new_vertex);
      new_ver->next = NULL;
      new_ver->edge = NULL;
    }
    if(curr != NULL){
      while(curr != NULL){
        if(strcmp(curr->vertex_name,new_vertex) == 0)
          return 0;
        prev = curr;
        curr = curr->next;
      }
      prev->next = new_ver;
      graph->size++;
      return 1;
    }
    else{
      graph->root = new_ver;
      graph->size ++;
      return 1;
    }
  }
  return 0;
}
/* Get how many vertices in the current graph */
int num_vertices(Graph graph){
  return graph.size;
}
/* check whether the graph parameter has the vertex called name*/
int has_vertex(Graph graph, const char name[]){
  Vertex* curr = NULL;
  if(graph.root == NULL || name == NULL)
    return 0;
  if(graph.root != NULL){
    curr = graph.root;
    while(curr != NULL){
      if(strcmp(curr->vertex_name,name) == 0)
        return 1;
      curr = curr->next;
    }
  }
  return 0;
}
/* This function return a newly created dynamically-allocated array of pointers to 
** characters point to the names of the vertices in the 
** graph with increasing lexicographic order.
*/
char **get_vertices(Graph graph){
  char **result;
  int counter = 0;
  int i = 0;
  int j = 0;
  Vertex* curr;
  if(graph.root == NULL)
    result = malloc(sizeof(char));
  else{
    curr = graph.root;
    while(curr != NULL){
      counter++;
      curr = curr->next;
    }
    result = malloc(sizeof(char*) * (counter + 1));
    curr = graph.root;
    while (curr != NULL && i < counter){
      if(i>0){
        j = i;
        while(j>0 && strcmp(result[j-1],curr->vertex_name) > 0){
          result[j] = result[j-1];
          j--;
        }
      }
      result[j] =  malloc(strlen(curr->vertex_name)*sizeof(char) + 1);
      strcpy(result[j],curr->vertex_name);
      curr = curr->next;
      i++;
    }
    result[counter] = NULL; 
  }
  return result;
}
/* This function add a new edge to its parameter graph with the cost cost from vertix
** called source to the vertex called dest, if there is already an edge between the vertex
** source and vertex dest, change its cost to the parameter cost and return 1. If the graph 
** does not contain either of two vertices, should add the vertex(vertices) first.
*/
int add_edge(Graph *graph, const char source[], const char dest[], int cost){
  int check_source = 0;
  int check_dest = 0;
  int ans = 0;
  Vertex* temp;
  Edge* curr = NULL;
  Edge* prev = NULL;
  Edge* new_edge;
  /* if cost is negative, just return 0 */
  if (cost < 0 ||  source == NULL || dest == NULL || graph == NULL){
    return ans;
  }
  new_edge = malloc(sizeof(Edge));
  if(new_edge != NULL){
    new_edge->dest_vertex = malloc(sizeof(Vertex));
    new_edge->dest_vertex->vertex_name = malloc(sizeof(char) * (strlen(dest) + 1));
    strcpy(new_edge->dest_vertex->vertex_name,dest);
    new_edge->cost = cost;
    new_edge->next = NULL;
  }
  if(graph->root != NULL){
    temp = graph->root;
    while(temp != NULL){
      if(strcmp(temp->vertex_name,source) == 0)
        check_source = 1;
      if(strcmp(temp->vertex_name,dest) == 0)
        check_dest = 1;
      temp = temp->next;
    }
    /*If the graph does not contain the vertex source or dest, add it first*/
    if(check_source == 0){
      add_vertex(graph,source);
      check_source = 1;
    }
    if(check_dest == 0){
      add_vertex(graph,dest);
      check_dest = 1;
    }
    if(check_source && check_dest == 1){
      temp = graph->root;
      while(temp != NULL){
        if(strcmp(temp->vertex_name,source) == 0 && check_dest == 1){
	  if(temp->edge != NULL){
	    curr = temp->edge;
	    while(curr != NULL && ans == 0){
	      if(curr->dest_vertex != NULL && curr->dest_vertex->vertex_name != NULL &&
		 strcmp(curr->dest_vertex->vertex_name,dest) == 0){
		free(new_edge->dest_vertex->vertex_name);
		free(new_edge->dest_vertex);
		free(new_edge);
		curr->cost = cost;
		ans = 1;
		return ans;
	      }
	      prev = curr;
	      curr = curr->next;
	    }
	    if(ans == 0){
	      prev->next = new_edge;
	      ans = 1;
	    }
	  }
	  else{
	    temp->edge = new_edge;
	    ans = 1;
	  }
	}
	temp = temp->next;
      }
    }
  }
  return ans; 

}
/* This funtion should return the cost of the edge in its current parameter which goes 
** from vertex named source to the vertex named dest
*/
int get_edge_cost(Graph graph, const char source[], const char dest[]){
  int check_source = 0;
  int check_dest = 0;
  Vertex* temp;
  Edge* curr;
  if (source == NULL || dest == NULL){
    return -1;
  }
  if(graph.root != NULL){
    temp = graph.root;
    while(temp != NULL){
      if(strcmp(temp->vertex_name,source) == 0)
	check_source = 1;
      if(strcmp(temp->vertex_name,dest) == 0)
	check_dest = 1;
      temp = temp->next;
    }
    if (check_source && check_dest == 0)
      return -1;
    if (check_source && check_dest == 1){
      temp = graph.root;
      while(temp != NULL){
	if (strcmp(temp->vertex_name,source) == 0){
	  if (temp->edge != NULL){
	    curr = temp->edge;
	    while(curr != NULL){
	      if(strcmp(curr->dest_vertex->vertex_name,dest) == 0)
		return curr->cost;
	      curr = curr->next;
	    }
	  }
	}
	temp = temp->next;
      }
    }
  }
  return -1;
}
/*This function should return how many neighbors the parameter vertex has*/
int num_neighbors(Graph graph, const char vertex[]){
  int count = 0;
  int check_vertex = 0;
  Vertex* temp;
  Edge* curr;
  if(vertex == NULL || graph.root == NULL)
    return -1;
  if(graph.root != NULL){
    temp = graph.root;
    while(temp != NULL && check_vertex == 0){
      if(strcmp(temp->vertex_name,vertex) == 0){
	check_vertex = 1;
	if(temp->edge != NULL){
	  curr = temp->edge;
	  while(curr != NULL){
	    if(curr->dest_vertex != NULL)
	      count++;
	    curr = curr->next;
	  }
	}
      }
      temp = temp->next;
    }
  }
  if(check_vertex == 0)
    return -1;
  else
    return count;
}
/* This function return a newly-created dynamically allocated array
** of pointers to copies of the names of the neighbors of parameter vertex
** with increasing lexicographic order.
*/
char **get_neighbors(Graph graph, const char vertex[]){
  char **result;
  int counter = 0;
  int i = 0;
  int j = 0;
  int k = 0;
  int check_ver = 0;
  Vertex* temp;
  Edge* curr;
  if(vertex == NULL || graph.root == NULL){
     result = malloc(sizeof(char));
     result[0] = NULL;
  }
  else{
    if(graph.root!= NULL){
      temp = graph.root;
      while(temp != NULL){
	counter++;
	temp = temp->next;
      }
      result = malloc(sizeof(char*) * (counter + 1));
      temp = graph.root;
      while(temp != NULL && i < counter){
	if(strcmp(temp->vertex_name,vertex) == 0){
	  check_ver = 1;
	  if(temp->edge != NULL){
	    curr = temp->edge;
	    while(curr != NULL && j < counter){
	      if(i>=0){
		k = j;
		while(k>0 && strcmp(result[k-1],curr->dest_vertex->vertex_name) > 0){
		  result[k] = result[k-1];
		  k--;
		}
	      }
	      result[k] = malloc((strlen(curr->dest_vertex->vertex_name) +1)*sizeof(char));
	      strcpy(result[k],curr->dest_vertex->vertex_name);
	      curr = curr->next;
	      j++;
	    }
	  }
	}
	temp = temp->next;
	i++;
      }
      if(check_ver == 1){
	 result[counter] = NULL;
      }
    }
  }
  return result;
}
/*helper has_edge function to check whether there is an edge between source and dest*/
int has_edge(Graph graph, const char source[], const char dest[]){
  Vertex *curr;
  Edge *temp;
  if(graph.root == NULL || !has_vertex(graph,source) || !has_vertex(graph,dest))
    return 0;
  else{
    curr = graph.root;
    while(curr != NULL){
      if(strcmp(curr->vertex_name,source) == 0){
	if(curr->edge != NULL){
	  temp = curr->edge;
	  while(temp != NULL){
	    if(strcmp(temp->dest_vertex->vertex_name,dest) == 0)
	      return 1;
	    temp = temp->next;
	  }
	}
      }
      curr = curr->next;
    }
  }
  return 0;
}
/* This function should free all the dynamically-allcoated memory 
** of the strings in the array strings, then free the array strings itself
*/
void free_string_list(char **strings){
  int i = 0;
  if(strings){
    while(strings[i]){
      /* free the strings in the array strings*/
      free(strings[i++]);
    }
    /* free strings itself */
    free(strings);
  }
}
/* This function should deallocate all dynamically memory that is used in Graph
** variable that parameter graph points to, destorying the graph and all its date 
** in the process.
*/
void clear_graph(Graph *graph){
  Vertex *curr, *prev = NULL;
  Edge *temp, *prev_edge = NULL;
  if(graph == NULL || graph->root == NULL)
    return;
  else{
    if(graph->root != NULL){
      curr = graph->root;
      while(curr != NULL){
	prev = curr;
	curr = curr->next;

	if(prev->edge != NULL){
	  temp = prev->edge;
	  while(temp != NULL){
	    prev_edge = temp;
	    temp = temp->next;
	    free(prev_edge->dest_vertex);
	    free(prev_edge);
	    prev_edge = NULL;
	  }
	}
	free(prev->vertex_name);
	free(prev);
	prev = NULL;  
      }
    }
    graph = NULL;
  }
}
/*This function should remove the edge going from source to dest in its parameter
** graph, if either source or dest are not present in the graph, or if they are not
**present in the graph, or if there are no edge between them, the function should has
**no effects and just return 0*/
int remove_edge(Graph *graph, const char source[], const char dest[]){
  int result;
  Vertex *curr;
  Edge *temp,*prev_edge = NULL;
  /*check whether the parameter is NULL */
  if(graph == NULL || source == NULL || dest == NULL)
    result = 0;
  /*check whether the graph has those vertices*/
  else if(has_vertex(*graph,source) == 0 || has_vertex(*graph,dest) == 0)
    result = 0;
  /*check whether there has edge between those vertices */
  else if(has_edge(*graph,source,dest) == 0)
    result = 0;
  else{
    if(graph->root != NULL){
      curr = graph->root;
      while(curr != NULL && strcmp(curr->vertex_name,source)!= 0){
	curr = curr->next;
      }
      if(curr != NULL){
	if(curr->edge != NULL){
	  temp = curr->edge;
	  while(temp != NULL && temp->dest_vertex != NULL 
		&& strcmp(temp->dest_vertex->vertex_name,dest) != 0){
	    prev_edge = temp;
	    temp = temp->next;
	  }
	  if(temp != NULL){
	    /*remove edge*/
	    if(prev_edge == NULL)
	      curr->edge = temp->next;
	    else
	      prev_edge->next = temp->next;
	    free(temp->dest_vertex->vertex_name);
	    free(temp->dest_vertex);
	    free(temp);
	    result = 1;
	  }
	}
      }
    }
  }
  return result;
}
/* This function should remove the vertex parameter from its parameter graph
** If vertex is not a vertex in the graph, the function should have no effect 
** and just return 0.
*/
int remove_vertex(Graph *graph, const char vertex[]){
  int result = 0;
  Vertex *curr, *oth_curr, *prev = NULL;
  Edge *temp, *oth_temp,*temp_prev;
  /* check the parameter and whether the vertex is in the graph*/
  if(graph == NULL || vertex == NULL || has_vertex(*graph,vertex) == 0)
    result = 0;
  else {
    if(graph->root != NULL){
      curr = graph->root;
      while(curr != NULL && strcmp(curr->vertex_name,vertex) != 0){
	prev = curr;
	curr = curr->next;
      }
      if(curr != NULL){
	oth_curr = graph->root;
	while(oth_curr != NULL){
	  if(oth_curr->edge != NULL){
	    temp = oth_curr->edge;
	    while(temp != NULL){
	      if(strcmp(temp->dest_vertex->vertex_name,vertex) == 0){
		temp_prev = temp;
		temp = temp->next;
		/*remove incoming edge*/
		free(temp_prev);
	      }
	      else{
		temp = temp->next;
	      }
	    }
	  }
	  oth_curr = oth_curr->next;
	}
	if(curr->edge != NULL){
	  oth_temp = curr->edge;
	  while(oth_temp != NULL){
	    /*remove the edge list for vertex*/
	    curr->edge = curr->edge->next;
	    free(oth_temp);
	    oth_temp = curr->edge;
	  }
	}
	if(prev == NULL)
	  /*remove vertex*/
	  graph->root = curr->next;
	else 
	  prev->next = curr->next;
	free(curr);
	graph->size--;
	result = 1;
      }
    }
  }
  return result;
}
