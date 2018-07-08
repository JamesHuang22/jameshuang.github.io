/* NAME: ZHIYU HUANG
** UID: 114622518
** Section: 0306
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trav-stack.h"

/* (c) Larry Herman, 2017.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

/* In this test, I write serveral tests to test all the functions of the stack 
** implementaion.
*/

static void test1(void);
static void test2(void);
/* new added tests */
static void test3(void);
static void test4(void);
static void test5(void);
static void test6(void);
static void test7(void);
static void test8(void);
static void test9(void);
static void test10(void);
static void test11(void);
static void test12(void);

static void test1(void) {
  Trav_stack trav_stack;

  init(&trav_stack);

  push(&trav_stack, "Kangaroo");
  push(&trav_stack, "Llama");
  push(&trav_stack, "Giraffe");
  push(&trav_stack, "Platypus");
  push(&trav_stack, "Parrot");

  if (size(trav_stack) != 5) {
    printf("Bug found- size() was wrong!\n");
    exit(FOUND_BUG);
  } else clear(&trav_stack);
}

static void test2(void) {
  Trav_stack trav_stack;
  char *element;

  init(&trav_stack);

  push(&trav_stack, "Kangaroo");
  push(&trav_stack, "Llama");
  push(&trav_stack, "Giraffe");
  push(&trav_stack, "Platypus");
  push(&trav_stack, "Parrot");

  element= read(trav_stack);
  if (element == NULL || strcmp(element, "Parrot") != 0) {
    printf("Bug found- read() was wrong!\n");
    exit(FOUND_BUG);
  } else clear(&trav_stack);
}

/* Test of the push() function */
static void test3(void){
  Trav_stack trav_stack;
  init(&trav_stack);

  push(&trav_stack, "abc");
  push(&trav_stack, "bcd");
  push(&trav_stack, "xyz");
  push(&trav_stack, "wrt");
  push(&trav_stack, "pop");
  push(&trav_stack, "hop");

  if(size(trav_stack) != 6){
    printf("Bug found- push() was wrong!\n");
    exit(FOUND_BUG);
  }else clear(&trav_stack);

}

/* Test of the pop function */
static void test4(void){
  Trav_stack trav_stack;
  init(&trav_stack);

  push(&trav_stack, "abc");
  push(&trav_stack, "bcd");
  push(&trav_stack, "hgs");
  push(&trav_stack, "uha");
  push(&trav_stack, "hya");

  pop(&trav_stack);
  pop(&trav_stack);
  pop(&trav_stack);

  if(size(trav_stack) != 2){
    printf("Bug found- pop2 was wrong\n");
    exit(FOUND_BUG);
  }
  else clear(&trav_stack);

}
/* Test of the pop() function when the graph is empty*/
static void test5(void){
  Trav_stack trav_stack;
  init(&trav_stack);

  if (pop(&trav_stack) != 0 ){
    printf("Bug found- pop() was wrong!\n");
    exit(FOUND_BUG);
  }else clear(&trav_stack);
}

/* Test the down() push() and pop()function */
static void test6(void){
  Trav_stack trav_stack;
  init(&trav_stack);

  push(&trav_stack, "abc");
  push(&trav_stack, "bcd");
  push(&trav_stack, "hgs");
  
  down(&trav_stack);
  down(&trav_stack);
  down(&trav_stack);

  if (pop(&trav_stack) != 0 ){
    printf("Bug found- down(),pop() was wrong!\n");
    exit(FOUND_BUG);
  }else clear(&trav_stack);
}

/* Test of the reset() function */
static void test7(void){
  Trav_stack trav_stack;
  init(&trav_stack);

  push(&trav_stack, "sdf");
  push(&trav_stack, "bsa");
  push(&trav_stack, "mgs");
  down(&trav_stack);
  down(&trav_stack);
  down(&trav_stack);
/* reset the stack */
  reset(&trav_stack);

  if(pop(&trav_stack) != 1 ){
    printf("Bug found- reset was wrong!\n");
    exit(FOUND_BUG);
  }else clear(&trav_stack);
}
/* Test fot the read() function */
static void test8(void){
  Trav_stack trav_stack;
  char *element;
  init(&trav_stack);
  
  push(&trav_stack, "sdf");
  push(&trav_stack, "bsa");
  push(&trav_stack, "mgs");
  push(&trav_stack, "wer");
  push(&trav_stack, "bwe");
  push(&trav_stack, "mds");


  pop(&trav_stack);
  pop(&trav_stack);

  push(&trav_stack, "abc");
  down(&trav_stack);

  element= read(trav_stack);

  if (element == NULL || strcmp(element, "wer") != 0) {
    printf("Bug found- read() was wrong!\n");
    exit(FOUND_BUG);
  } else clear(&trav_stack);

}
/* Test for the down funciton when the graph is empty */
static void test9(void){
  Trav_stack trav_stack;

  init(&trav_stack);
  push(&trav_stack,"abc");
  push(&trav_stack,"bcd");
  push(&trav_stack,"hua");
  pop(&trav_stack);
  pop(&trav_stack);
  pop(&trav_stack);

  if(down(&trav_stack) != 0){
    printf("Bug found- down() was wrong!\n");
    exit(FOUND_BUG);
  }else clear(&trav_stack);

}

/* Test down() and read() function */
static void test10(void){
  Trav_stack trav_stack;
  char *element;
  init(&trav_stack);
  
  push(&trav_stack, "abc");
  push(&trav_stack, "bcd");
  push(&trav_stack, "xyz");
  push(&trav_stack, "she");
  push(&trav_stack, "edc");
  push(&trav_stack, "lbj");
  push(&trav_stack, "uha");
  push(&trav_stack, "haa");
  push(&trav_stack, "nba");
  
  down(&trav_stack);
  down(&trav_stack);
  down(&trav_stack);
  
  pop(&trav_stack);
  pop(&trav_stack);



  element= read(trav_stack);

  if (element == NULL || strcmp(element, "she") != 0 || size(trav_stack) != 7) {
    printf("Bug found- read() down() was wrong!\n");
    exit(FOUND_BUG);
  } else clear(&trav_stack);

}
/* Test the reset() function */
static void test11(void){
  Trav_stack trav_stack;
  char *element;
  init(&trav_stack);
  
  push(&trav_stack, "abc");
  push(&trav_stack, "bas");
  push(&trav_stack, "ayz");
  push(&trav_stack, "shy");
  push(&trav_stack, "ddc");
  push(&trav_stack, "lfj");

  down(&trav_stack);
  down(&trav_stack);
  down(&trav_stack);

  reset(&trav_stack);
  pop(&trav_stack);
  pop(&trav_stack);
  element= read(trav_stack);


  if (element == NULL || strcmp(element, "shy") != 0 || size(trav_stack) != 4) {
    printf("Bug found- read(),down() was wrong!\n");
    exit(FOUND_BUG);
  } else clear(&trav_stack);

}
/* Test the clead() function() */
static void test12(void){
  Trav_stack trav_stack;
  init(&trav_stack);

  push(&trav_stack, "huq");
  push(&trav_stack, "bas");
  push(&trav_stack, "aaz");
  push(&trav_stack, "uyw");

  clear(&trav_stack);
 
  init(&trav_stack);
  push(&trav_stack, "huq");
  push(&trav_stack, "bas");

  if (size(trav_stack) != 2) {
    printf("Bug found- clear() was wrong!\n");
    exit(FOUND_BUG);
  }else clear(&trav_stack);

}
int main() {
  test1();
  test2();

  test3();
  test4();
  test5();
  test6();
  test7();
  test8();
  test9();
  test10();
  test11();
  test12();
  
  printf("No bugs were detected!\n");

  return CORRECT;
}
