/* NAME: ZHIYU HUANG
** UID: 114622518
** Section: 0306
*/

/* In this project, it tend to implement a small shell program which 
** simulate a UNIX utility xargs,with two mode standard mode and line
** at time mode.
*/
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <err.h>
#include <sys/wait.h>
#include "safe-fork.h"
#include "split.h"

int main(int argc, char const *argv[])
{
  char **arg_temp;
  char **args;
  char *com_line = NULL;
  char *chr;

  char line[1000];
  int status = 0;
  int ch;
  int mode = 0;
  int pid;

  arg_temp = (char **)argv;
  arg_temp +=1 ;

 /* In this for loop, find the -i to determine whether is */
  /* line-at -time-mode or standard mode */
  for (j = 0; j < argc; j++){
    if(strcmp(argv[j],"-i") == 0)
      /* standard mode for 0, line-at-time-mode for 1 */
      mode = 1;
  }

  arg_temp = (char**)argv + 1;
  if(mode == 1){
    arg_temp++;
  }
  if (argc == 1 || (argc == 2 && mode == 1)){
    /* Run the UNIX echo utility */
    com_line = "/bin/echo";
  }
  if (com_line == NULL){
    com_line = *arg_temp++;
  }
  argc = (char **)argv + argc - arg_temp;
  /* number of target arguments */

  if(mode == 0){
   chr = line;
    while(fgetc(stdin) != EOF){
      ch = fgetc(stdin)
      if(ch == '\n')
        ch = ' ';
      *chr++ = ch;
    }
    *chr++ = '\n';
    *chr = 0;
  }
  while(fgets(line,sizeof(line),stdin) != NULL || mode == 0){
    int len = 1;
    int i = argc;
    char **curr;
    args= split(line);
    curr = args;
    while(*curr++ != NULL)
      len++;
    args = realloc(args, (len + argc + 1) * sizeof(char*));
    memmove(args + argc + 1, args, sizeof(char*) * len);
    *args = com_line;
    while(i != 0){
      *(args + i) = *(arg_temp + i - 1);
      i--; 
    }
    curr = args;
    pid = safe_fork();
    if (pid > 0){
      wait(&status);
      curr = args + argc + 1;
      while(*curr != NULL){
        free(*curr++);
      }
      free(args);
      if(status != 0)
        exit(1);
      mode = 1;
    }
    else if(pid == 0){
      /* child process to run the target program */
      execvp(args[0], args);
      exit(1);
    }
    else exit(1);
    
  }
  if(feof(stdin))
    exit(0);
  else
    exit(1);
  return 0;

}
