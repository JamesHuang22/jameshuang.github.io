/* NAME: ZHIYU HUANG
** UID: 114622518
** Section: 0306
*/
#include <stdio.h>
#include <string.h>
#include "trav-stack.h"

/* This funciton to initialize its Trav_stack parameter 
** to be an empty stack
*/
void init(Trav_stack *const trav_stack){
  trav_stack->head = NULL;
  trav_stack->size = 0;
  trav_stack->cursor = (Node*)malloc(sizeof(Node*));
} 
/* helper funtion to check whether the stack is empty or not */
int is_Empty(Trav_stack *const trav_stack){
  if(trav_stack->head == NULL)
    return 1;
  else
    return 0;
}
/* This function should add new element at the top of its trav_stack parameter 
** and preserve the cursor's depth 
*/
int push(Trav_stack *const trav_stack, const char new_element[]){
  Node* temp;
  temp = (Node*)malloc(sizeof(*temp));
  if(temp != NULL){
    temp->name = malloc(sizeof(char) * (strlen(new_element) + 1));
    strcpy(temp->name,new_element);
  }
  /*check whether the parameter is NULL, if is NULL, the function has no effect return 0; */
  if (trav_stack == NULL || new_element == NULL)
    return 0;
  else{
    temp->next = trav_stack->head;
    trav_stack->head = temp;
    trav_stack->cursor = trav_stack->head;
    trav_stack->size++;
    return 1;
  }
  return 0;
}

/* This function should return the size of the current trav_stacl parameter */
int size(Trav_stack trav_stack){
  if (trav_stack.head == NULL)
    return 0;
  return trav_stack.size;
}
/* This function should remove the element at the top of the stack parameter 
** if the cursor is not at the bottom and the stack is not empty
*/
int pop(Trav_stack *const trav_stack){
  Node* temp;
  Node* oth_temp;
  /* Node* oth_temp;*/
  /* special case for tor empty stack and cursor is and the buttom of the stack*/
  if(is_Empty(trav_stack) == 1 || trav_stack == NULL || trav_stack->cursor == NULL 
    || (trav_stack->cursor->next == NULL && trav_stack->size >= 2)){
    return 0;
  }
  else{
    /* remove the top element */
    temp = trav_stack->head;
    trav_stack->head = trav_stack->head->next;
    free(temp->name);
    temp->name = NULL;
    temp->next = NULL;
    free(temp);
    temp = NULL;
    oth_temp = trav_stack->cursor->next;
    trav_stack->cursor = oth_temp;
    trav_stack->size--;
    return 1;
  }
  return 0;
}

/* This function should increase the cursor's depth by 1 and return 1
** if the stack is empty and cursor is in bottom at the stack the function 
** should return 0 and do nothing 
*/

int down(Trav_stack *const trav_stack){
  Node* temp;
  /* if the stack is empty and the cursor is at the bottom of the stack */
  if(trav_stack == NULL || is_Empty(trav_stack) == 1 || trav_stack->cursor->next == NULL)
    return 0;
  else{
    temp = trav_stack->cursor->next;
    trav_stack->cursor = temp;
    return 1;
  }
  return 0;
}
/* This function should set the cursor's depth to 0 if the stack is not empty */
void reset(Trav_stack *const trav_stack){
  if(is_Empty(trav_stack) == 0){
    trav_stack->cursor = trav_stack->head;
  }
}

/* This function should return a dynamically-allocated copy of the element 
** at the cursor of the trav_stack parameter.
*/
char *read(Trav_stack trav_stack){
  char *result;
  /* if the parameter is NULL, the function should return NULL.*/
  if (trav_stack.head == NULL)
    return NULL;
  else{
    result = malloc(sizeof(char) * (strlen(trav_stack.cursor->name) + 1));
    strcpy(result,trav_stack.cursor->name);
  }
  return result;
}
/* This function should deallocate all the dynamically-allocated memory that 
** is used by the entire Trav_stack trav_stack parameter point to without any memory leak
*/
void clear(Trav_stack *const trav_stack){
  Node* temp;
  Node* next_node;
  if(trav_stack->head != NULL){
    temp = trav_stack->head;
    while(temp != NULL){
      next_node = temp->next;
      free(temp->name);
      temp->name = NULL;
      free(temp);
      temp = next_node;
    }
  }
}


