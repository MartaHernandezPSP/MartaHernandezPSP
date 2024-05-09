#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


void main()
{
	int fd[2];
	pid_t pid;

	pipe(fd);

	pid=fork();

	if(pid==0)//hijo
	{
		printf("Nombre del alumno: Marta \n");

	}
	else//padre
	{
		wait(NULL);
        	printf("Proceso P1\n");
        	printf("Pid P1: %d y Pid P2: %d \n", getpid(), pid);
		
	}


exit(0);

}
