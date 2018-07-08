#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

Student *new_student(const char name[], unsigned int id, float shoe_size){
  Student *new_stu = malloc(sizeof(*new_stu));
  if (name == NULL){
    new_stu->name = malloc(sizeof(char));
    strcpy(new_stu->name, "");
    new_stu->id = id;
    new_stu->shoe_size = shoe_size;
  }
  else{
    new_stu->name = malloc(strlen(name) + 1);
    strcpy(new_stu->name,name);
    new_stu->id = id;
    new_stu->shoe_size = shoe_size;
  }
  return new_stu;
}

unsigned int has_id(Student *const student, unsigned int id){
  if (student != NULL){
    if (student->id == id)
      return 1;
  }
  return 0;
}
int has_name(Student *const student, const char name[]){
  if (name  == NULL)
    return 0;
  if (student != NULL){ 
    if(strcmp((student->name),name) != 0)
      return 0;
    else
      return 1;
  }
  return 0;
}

unsigned int get_id(Student *const student){
  if (student != NULL){
    return student->id;
  }
  return 0;
}
float get_shoe_size(Student *const student){
  if(student != NULL){
    return student->shoe_size;
  }
  return 0;
}
void change_shoe_size(Student *const student, float new_shoe_size){
  if(student != NULL){
    student->shoe_size = new_shoe_size;
  }
}
void change_name(Student *const student, const char new_name[]){
  if(student != NULL){
    free(student->name);
    if(new_name == NULL){
      student->name = malloc(sizeof(char));
      strcpy(student->name,"");
    }
    else{
      student->name = malloc((strlen(new_name)+ 1));
      strcpy(student->name,new_name);
    }
  }
}
void copy_student(Student *student1, Student *const student2){
  if (student1 != NULL && student2 != NULL){
    if(sizeof(student1->name) == sizeof(student2->name)){
      student1->name = student2->name;
      student1->id = student2->id;
      student1->shoe_size = student2->shoe_size;
    }
  }
}
