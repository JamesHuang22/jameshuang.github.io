#define _XOPEN_SOURCE 600
#include "safe-fork.h"
#include "split.h"
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))

int main(int argc, char const *argv[])
{
    int pipefd[2];
    char **args, **temp, *command = NULL;
    /* args is a null terminating array that    */
    /* stores all the arguments for the passed  */
    /* in command.                              */
    char data[1000];
    int status = 0, mode = 0, c, pid;
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

    if(command == NULL){
        command = *temp;
        temp ++;
    }

    /* calculate number of arguments */
    /* starting from temp            */
    argc = (char **)argv + argc - temp;
    args = temp;

    if(mode == 0){
        FILE *write_chr;
        if(pipe(pipefd) == -1)
            exit(-1);
        write_chr = fdopen(pipefd[1], "a");
        while((c = fgetc(stdin)) != EOF){
            /* replace new line character to space */
            if(c == 10)
                c = 32;
            fputc(c, write_chr);
        }
        fputc(10, write_chr);
        dup2(pipefd[0], STDIN_FILENO);
        fclose(write_chr);
        close(pipefd[1]);
        close(pipefd[0]);
    }

    while(fgets(data, sizeof(data), stdin) != NULL){
        int size = 1, count = argc;
        char **itr;
        temp = split(data);
        itr = temp;
        while(*itr++ != NULL)
            size++;
        temp = realloc(temp, sizeof(char*) * (size + argc + 1));
        memmove(temp + argc + 1, temp, sizeof(char*) * size);
        *temp = command;
        while(count != 0){
            *(temp + count) = *(args + count - 1);
            count--;
        }

        itr = temp;
        pid = safe_fork();

        if(pid == 0){
            execvp(temp[0], temp);
            exit(1);
        }
        else if(pid > 0){
            wait(&status);
            itr = temp + argc + 1;
            while(*itr != NULL)
                free(*itr++);
            free(temp);
            if(status != 0)
                exit(1);
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