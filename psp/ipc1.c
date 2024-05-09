#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


void main()
{
	int fd[2];
	char buffer[10];
	pid_t pid;

	pipe(fd);

	pid=fork();

	if(pid==0)
	{
		close(fd[1]);
		printf("\n Soy el hijo con un PID: %d \n", getpid());
		read(fd[0],buffer,10);
		printf("Mensajes del pipe: %s \n",buffer);

	}
	else
	{
		close(fd[0]);
		printf("Padre escribe en el PIPE \n");
		write(fd[1],"fecha/hora",10);
		
	}


exit(0);

}
