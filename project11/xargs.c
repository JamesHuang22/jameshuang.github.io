/* NAME: ZHIYU HUANG
** UID: 114622518
** Section: 0306
*/
#define _XOPEN_SOURCE 600
#include "safe-fork.h"
#include "split.h"
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#define NUMELEMS(x)  (sizeof(x) / sizeof((x)[0]))
int main(int argc, char const *argv[])
{
  int pipefd[2];
  char **args;
  char **temp;
  char *comline = NULL;

  char line[1000];
  int status = 0;
  int mode = 0;
  int ch;
  int pid;

  temp = (char **)argv;
  temp +=1 ;

  /* In this while loop, find the -i */
  while (temp - (char **)argv < argc){
    if (strcmp(*temp, "-i") == 0){
      mode = 1;
    }
    temp += 1;
  }

  temp = (char**)argv + 1;
  if(mode == 1){
    /* line at time mode */
    temp++;
  }
  if (argc == 1 || (argc == 2 && mode != 0)){
    comline = "echo";
  }
  if (comline == NULL){
    comline = *temp;
    temp += 1;
  }
  argc = (char **)argv + argc - temp;
  args = temp;

  if(mode == 0){
    FILE *write_chr;
    if(pipe(pipefd) == -1){
      /* pipe error occurs */
      exit(-1);
    }
    write_chr = fdopen(pipefd[1], "a");
    while((ch = fgetc(stdin)) != EOF){
      if(ch == '\n')
        ch = ' ';
      fputc(ch,write_chr);
    }
    fputc('\n',write_chr);
    dup2(pipefd[0],STDIN_FILENO);
    fclose(write_chr);
    close(pipefd[1]);
    close(pipefd[0]);
  }

  while(fgets(line,sizeof(line),stdin) != NULL){
    int len = 1;
    int i = argc;
    char **curr;
    temp = split(line);
    curr = temp;
    while(*curr++ != NULL)
      len++;
    temp = realloc(temp, (len + argc + 1) * sizeof(char*));
    memmove(temp + argc + 1, temp, sizeof(char*) * len);
    *temp = comline;
    while(i != 0){
      *(temp + i) = *(args + i - 1);
      i--; 
    }
    curr = temp;
    pid = safe_fork();
    if (pid > 0){
      wait(&status);
      curr = temp + argc + 1;
      while(*curr != NULL){
        free(*curr++);
      }
      free(temp);
      if(status != 0)
        exit(1);
    }
    else if(pid == 0){
      execvp(temp[0], temp);
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