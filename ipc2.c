#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


void main()
{
	int fd[2];
	char buffer[4];
	pid_t pid;
	
	int num1=18; 
	int num2=25;
	int num3=67;
	int suma=0;
	
	char caracter ='+';
	
	pipe(fd);

	pid=fork();

	if(pid==0)
	{
		close(fd[1]);
		printf("Soy el hijo : \n");
        	read(fd[0], buffer, 4);
        	printf("Mensajes del pipe: %d, %d, %d, %c \n", buffer[0], buffer[1], buffer[2], buffer[3]);
        	suma=buffer[0]+buffer[1]+buffer[2];
		printf("La suma es: %d \n",suma);

	}
	else
	{
		close(fd[0]);
		printf("EL padre escribe en el pipe: \n");
		buffer[0]=num1;
		buffer[1]=num2;
		buffer[2]=num3;
		buffer[3]=caracter;
		write(fd[1], buffer, 4);
		wait(NULL);
		
	}


exit(0);

}
