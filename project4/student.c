  #include <stdio.h>
  #include "student.h"


  Student new_student(const char name[], unsigned int id, float shoe_size){
    int i; 
    Student new_stu;
    if( name == NULL ){
      for (i = 0; i < NAME_LEN; i++){
        new_stu.name[i] = '\0';
      }
      new_stu.id = id;
      new_stu.shoe_size = shoe_size;
    }
      
    else{
      for (i = 0; i < NAME_LEN; i++){
        new_stu.name[i] = name[i];
      }
      new_stu.id = id;
      new_stu.shoe_size = shoe_size;
    }
    return new_stu;
  }

  void init_student(Student *const student, const char name[], unsigned int id,
                    float shoe_size){
    int i;
    if (student != NULL) {
      if ( name == NULL ){
        for (i = 0; i < NAME_LEN; i++){
    (*student).name[i] = '\0';
        }
        (*student).id = id;
        (*student).shoe_size = shoe_size;
      }
      else{
        for (i = 0; i < NAME_LEN; i++){
    (*student).name[i] = name[i];
        }
        (*student).id = id;
        (*student).shoe_size = shoe_size;
      }
    }

  }
  unsigned int has_id(Student student, unsigned int id){
    if (student.id == id)
      return 1;
    else 
      return 0;
  }

  int has_name(Student student, const char name[]){
    int i;
    if (name == NULL){
      return 0;
    }
    for ( i = 0; i < NAME_LEN; i++){
      if (student.name[i] == '\0' && name[i] == '\0')
        return 1;
      if (student.name[i] != name[i])
        return 0;
    }
    return 1;
  }
  unsigned int get_id(Student student){
    return student.id;
  }
  float get_shoe_size(Student student){
    return student.shoe_size;
  }
  Student change_shoe_size(Student student, float new_shoe_size){
    student.shoe_size = new_shoe_size;
    return student;
  }
  void change_name(Student *const student, const char new_name[]){
    int i;
    if (student == NULL)
      return;
    if (new_name == NULL)
      for (i = 0; i < NAME_LEN; i++){
        (*student).name[i] = '\0';
      }
    else 
      for (i = 0; i < NAME_LEN; i++){
        (*student).name[i] = new_name[i];
      }

  }

