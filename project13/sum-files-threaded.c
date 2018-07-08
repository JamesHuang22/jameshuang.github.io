/* NAME: ZHIYU HUANG
** UID: 114622518
** Section: 0306
*/
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

/* (c) Larry Herman, 2017.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */
static void *sum(void *arg);
static void *sum(void *arg){
  int n;
  int *one_file_sum = malloc(sizeof(*one_file_sum));
  FILE *fp;
  char *name = (char *) arg;
    /* open the file with the filename argument */
  
  fp= fopen(name, "r");
  if (fp != NULL) {
    *one_file_sum= 0;
    fscanf(fp, "%d", &n);
    while (!feof(fp)) {
      *one_file_sum += n;
      fscanf(fp, "%d", &n);
    }
    fclose(fp);
  }
  return one_file_sum;
}
int main(int argc, char *argv[]) {
  int i;
  int all_files_total = 0;
  /* File file;*/
  void** ret_ptr = (void** )malloc((argc-1)* sizeof(void *));
  pthread_t *tids = malloc((argc - 1) * sizeof(pthread_t)); 
  for ( i = 0; i < argc - 1; i++){
    ret_ptr[i] = NULL;
  }
  for(i =1; i < argc; i++){
    pthread_create(&tids[i - 1], NULL, sum, argv[i]);
  }
  for (i = 1; i < argc; i++){
   pthread_join(tids[i -1], &ret_ptr[i - 1]);
   all_files_total += *(int*) ret_ptr[i - 1];
 }
 printf("%d\n", all_files_total);
 for ( i = 0; i < argc - 1; i++){
  free(ret_ptr[i]);
}
free(tids);
free(ret_ptr);
return 0;
}
