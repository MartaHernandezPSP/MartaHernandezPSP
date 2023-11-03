#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void main()
{
	int pipe1[2];
	int pipe2[2];
	char buffer1[1];
	char buffer2[1];
	pid_t pid;
	
	int num;
	int factorial;
	
	pipe(pipe1);
	pipe(pipe2);
	
	pid=fork();
	
	
	if(pid==0)//hijo
	{
		
		close(pipe1[1]);
        	read(pipe1[0], buffer1, 1);
        	printf("Soy el Hijo, el número aleatorio es: %d \n", buffer1[0]);
        	//
		for (int i = 1; i < buffer1[0]; i++) 
		{
       	 	factorial=factorial*i;
       	}
	
		close(pipe2[0]);
		printf("El hijo carga pipe2 con el número aleatorio \n");
		buffer2[0]=factorial;
		write(pipe2[1], buffer2, 1);
	
	}
	else//padre
	{
	
		num = 7;
		close(pipe1[0]);
		printf("El padre esta generando un número aleatorio \n");
		buffer1[0]=num;
		write(pipe1[1], buffer1, 1);
		//
		close(pipe2[1]);
        	read(pipe2[0], buffer2, 1);
        	printf("Soy el padre, factorial de %d es: %d \n",num, buffer2[0]);
	
	}

exit(0);

}

