/* NAME: ZHIYU HUANG
** UID: 114622518
** Section: 0306
*/
#include <stdio.h>
#include "graph.h"
#include <string.h>
/*
** In this project, I write the program that stores a graph. And I used 
** linked list data structure to implement the graph. 
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
      new_ver->vertex_name = malloc(strlen(new_vertex) + 1);
      strcpy(new_ver->vertex_name,new_vertex);
      new_ver->next = NULL;
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
  Edge* curr;
  Edge* new_edge;
  /* if cost is negative, just return 0 */
  if (cost < 0 ||  source == NULL || dest == NULL){
    return ans;
  }
  new_edge = malloc(sizeof(Edge));
  if(new_edge != NULL){
    new_edge->dest_vertex = malloc(sizeof(Vertex));
    new_edge->dest_vertex->vertex_name = malloc(strlen(dest) + 1);
    strcpy(new_edge->dest_vertex->vertex_name,dest);
    new_edge->cost = cost;
    new_edge->next = NULL;
  }
  if(graph->root != NULL){
    temp = graph->root;
    while(temp != NULL && check_source == 0 && check_dest == 0){
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
        if(strcmp(temp->vertex_name,source) == 0){
          curr = temp->edge;
          while(curr != NULL && ans != 1){
            if(strcmp(curr->dest_vertex->vertex_name,dest) == 0){
              curr->cost = cost;
              ans = 1;
            }
            curr = curr->next;
          }
          if(ans == 0){
            new_edge->next = temp->edge;
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
  if(vertex == NULL || graph.root == NULL)
    result = malloc(sizeof(char));
  else{
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
            if(i>0){
              k = j;
              while(k>0 && strcmp(result[k-1],curr->dest_vertex->vertex_name) > 0){
                result[k] = result[k-1];
                k--;
              }
            }
            result[k] = malloc(strlen(curr->dest_vertex->vertex_name)*sizeof(char)+1);
            strcpy(result[k],curr->dest_vertex->vertex_name);
            curr = curr->next;
            j++;
          }   
        }
      }
      temp = temp->next;
      i++;
    }
  }
  if(check_ver == 0)
    return NULL;
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
void free_string_list(char **strings){
  if(strings != NULL){
    free(*strings);
    strings = NULL;
  }
}
void clear_graph(Graph *graph){
  Vertex *curr = NULL,*temp = NULL;
  if(graph != NULL){
    curr = graph->root;
    while(curr != NULL){
      temp = curr->next;
      free(curr);
      curr = temp;
    }

  }
}
int remove_edge(Graph *graph, const char source[], const char dest[]){
  int result;
  Vertex *curr;
  Edge *temp;
  Edge *prev = NULL;
  if(graph == NULL || source == NULL || dest == NULL)
    result = 0;
  else if(has_vertex(*graph,source) == 0 || has_vertex(*graph,dest) == 0)
    result = 0;
  else if(has_edge(*graph,source,dest) == 0)
    result = 0;
  else{
    curr = graph->root;
    while(curr != NULL){
      if(strcmp(curr->vertex_name,source) == 0){
        if(curr->edge != NULL){
          temp = curr->edge;
          while(temp != NULL){
            if(strcmp(temp->dest_vertex->vertex_name,dest) == 0){
              if(prev == NULL)
                curr->edge = temp->next;
              else
                prev->next = temp->next;
              free(temp);
              result = 1;
            }
            prev = temp;
            temp = temp->next;
          }
        }
      }
      curr = curr->next;
    }
  }
  return result;
}
int remove_vertex(Graph *graph, const char vertex[]){
  int result = 0;
  Vertex *curr, *prev = NULL;
  Edge *temp;
  if(graph == NULL || vertex == NULL)
    result = 0;
  else{
    if(graph->root != NULL){
      curr = graph->root;
      while(curr != NULL && strcmp(curr->vertex_name,vertex) != 0 ){
  prev = curr;
  curr = curr->next;
      }
      if(curr != NULL){
  if(curr->edge != NULL){
    temp = curr->edge;
    while(temp != NULL){
      curr->edge = curr->edge->next;
      free(temp);
      temp = curr->edge;
    }
  }
  if(prev == NULL)
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


