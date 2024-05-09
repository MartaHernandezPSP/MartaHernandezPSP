#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


void main()
{
	pid_t pid,pid2,padre;

	padre = getpid();

	pid=fork();

	if(pid==0)//hijo
	{
		printf("HIJO 1 \n");
		
		printf("Pid Padre: %d , Pid Hijo 1: %d \n", getpid(), padre);

	}
	else//padre
	{
		pid2=fork();
		
		if(pid2==0)//hijo2
		{
			printf("HIJO 2 \n");
			printf("a dormir\n");
			sleep(10);
			printf("despierto\n");

		}
		else//padre
		{
			wait(NULL);
			wait(NULL);
			printf("PADRE \n");

		}

	
	
	}


exit(0);

}
