#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <err.h>
#include <sysexits.h>
#include "safe-fork.h"


int main(void){
	pid_t pid;
	int fd[2];

	pipe(fd);
	pid = safe_fork();

	if ( pid > 0){ /* parent process */
	int len;
	dup2(fd[0],STDIN_FILENO);
	close(fd[0]);
	close(fd[1]);

	scanf("%d", &len);
	if (len < 200){
		printf("Too short!\n");
		exit(1);
	}else{
		printf("Long enough!\n");
		exit(0);
	}
	
  }else if ( pid == 0){ /* child process */
		dup2(fd[1], STDOUT_FILENO);

		close(fd[0]);
		close(fd[1]);
		execl("/usr/bin/wc", "wc", "-w", NULL);
		err(EX_OSERR, "exec error");

	}else{
		err(EX_OSERR, "safe-fork error");
	}

}