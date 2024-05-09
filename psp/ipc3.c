#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


void main()
{
	int fd[2];
	char buffer[2];
	pid_t pid;

	int num1;
	int num2;
	
	
	int diferencia,producto,suma;
	double division;
	
	pipe(fd);

	pid=fork();

	if(pid==0)
	{
		num1 = (rand() % 50) + 1;
		num2 = (rand() % 50) + 1;
		close(fd[0]);
		printf("EL hijo escribe en el pipe: \n");
		buffer[0]=num1;
		buffer[1]=num2;
		write(fd[1], buffer, 2);
		wait(NULL);
		

	}
	else
	{
		close(fd[1]);
		printf("Soy el Padre : \n");
        	read(fd[0], buffer, 42);
        	printf("Mensajes del pipe: %d, %d \n", buffer[0], buffer[1]);
        	
        	suma=num1+num2;
        	
        	if(num1<num2)
        	{
        		diferencia=num2-num1;
        		division=num2/num1;
        	}
        	else
        	{
        		diferencia=num1-num2;
        		division=num1/num2;
        	}
        	
        	producto=num1*num2;

		printf("La suma es: %d \n",suma);
		printf("La resta es: %d \n",diferencia);
		printf("La multiplicaion es: %d \n",producto);
		printf("La division es: %lf \n",division);
		
	}


exit(0);

}






