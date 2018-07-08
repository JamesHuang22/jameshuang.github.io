#define _XOPEN_SOURCE 600
/* enabling functions such as fdopen */
#include "safe-fork.h"
#include "split.h"
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

/* 
** Yifan Yang
** 114733252
** the following codes implements a simple shell
** which has two modes: normal mode and line mode
** with -i option.
*/

int main(int argc, char const *argv[])
{
    char **args, **temp, *command = NULL;
    /* args is a null terminating array that    */
    /* stores all the arguments for the passed  */
    /* in command.                              */
    char data[1000];
    int status = 0, mode = 0;
    /* mode: 0-standard 1-line */
    temp = (char **)argv;
    temp += 1;

    /* search for -i option */
    while((temp - (char **)argv) < argc){
        if(strcmp(*temp, "-i") == 0)
            mode = mode | 1;
        temp += 1;
    }

    temp = (char **)argv + 1;
    if(mode == 1)
        temp ++;

    /* determine command*/
    if(argc == 1 || (argc == 2 && mode != 0))
        command = "echo";

    if(command == NULL)
        command = *temp++;

    /* calculate number of arguments */
    /* starting from temp            */
    argc += (char **)argv - temp;

    /* replace \n in input to space */
    /* by reading everyingthing in  */
    /* then redirect it to stdin    */

    /* just realized we can't use pipe */
    /* oh well i m just going to read  */
    /* everything and put that into an */
    /* array. Feelsbad.                */
    if(mode == 0){
        int c;
        char *chr;
        chr = data;
        while((c = fgetc(stdin)) != EOF){
            /* replace new line character to space */
            if(c == 10)
                c = 32;
            *chr++ = c;
        }
        *chr++ = 10;
        *chr = 0;
    }

    /* if it has more than one line of arguments, */
    /* fgets would itr it more times.             */
    while(mode == 0 || fgets(data, sizeof(data), stdin) != NULL){
        int size = 1, count = argc, pid;
        char **itr;
        /* construct args array for exec */
        args = split(data);
        itr = args;
        while(*itr++ != NULL)
            size++;
        args = realloc(args, sizeof(char*) * (size + argc + 1));
        memmove(args + argc + 1, args, sizeof(char*) * size);
        *args = command;
        while(count != 0){
            *(args + count) = *(temp + count - 1);
            count--;
        }

        itr = args;
        pid = safe_fork();

        if(pid == 0){
            execvp(args[0], args);
            exit(1);
        }
        else if(pid > 0){
            wait(&status);
            /* free dynamically allocated strings */
            itr = args + argc + 1;
            while(*itr != NULL)
                free(*itr++);
            /* free the args array */
            free(args);
            if(status != 0)
                exit(1);
            mode = 1;
        }
        else
            exit(1);
    }

    if(feof(stdin))
        exit(0);
    else
        exit(1);
    return 0;
}