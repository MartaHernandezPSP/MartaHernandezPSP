#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


void main()
{
	pid_t pid,pid2,padre;
	
	int opcion,operando1,operando2,solucion;
	
	int pipe1[2];
    	int pipe2[2];
    	
    	pipe(pipe1);
    	pipe(pipe2);
    	

	padre = getpid();

	pid=fork();

	if(pid==0)//hijo
	{
				
		pid2=fork();
		
		
		if(pid2==0)//hijo2
		{
			close(pipe2[1]); // Cerramos el descriptor de escritua en el hijo
        		read(pipe2[0], &solucion, sizeof(solucion));	
        		close(pipe2[0]);
        		
        		printf(" \n Proceso P3 pid = %d - Proceso padre pid = %d \n",getpid(),getppid());
			
			if(solucion%2==0)
			{
			
				printf(" \n Resultado de la operacion %d es par \n ",solucion);
			}
			else
			{
			
				printf(" \n Resultado de la operacion %d es impar \n ",solucion);
			
			}
			
			printf("\n Termina proceso 3");
			
		}
		else//hijo
		{
			close(pipe1[1]); // Cerramos el descriptor de escritua en el hijo
        		read(pipe1[0], &opcion, sizeof(opcion));
        		read(pipe1[0], &operando1, sizeof(operando1));
        		read(pipe1[0], &operando2, sizeof(operando2));
        		close(pipe1[0]);
        		
        		printf("\n Proceso P2 pid = %d - Proceso padre pid = %d \n ",getpid(),getppid());
        		
        		switch(opcion)
			{
				case 1: solucion = operando1 + operando2;
					printf("%d + %d = %d \n ",operando1,operando2,solucion);
					break;
				case 2: solucion = operando1 - operando2;
					printf("%d - %d = %d \n ",operando1,operando2,solucion);
					break;
				case 3: solucion = operando1 * operando2;
					printf("%d * %d = %d \n ",operando1,operando2,solucion);
					break;
				case 4: solucion = operando1 / operando2;
					printf("%d / %d = %d \n ",operando1,operando2,solucion);
					break;

			}
			
			close(pipe2[0]); // Cerramos el descriptor de lectura en el padre
        		write(pipe2[1], &solucion, sizeof(solucion));
			close(pipe2[1]);
			
			
		}

	}
	else//padre
	{
	
		printf("Proceso P1 pid : %d \n",padre);
		printf("***CALCULADORA***\n");
		printf("1.Sumar\n");
		printf("2.Restar\n");
		printf("3.Multiplicar\n");
		printf("4.División\n");
		
		printf("Seleccione la opcion deseada : ");
		scanf("%d", &opcion);
		
		printf("Introduce el primer operando : ");
		scanf("%d", &operando1);
		
		printf("Introduce el segundo operando : ");
		scanf("%d", &operando2);
		
		close(pipe1[0]); // Cerramos el descriptor de lectura en el padre
        	write(pipe1[1], &opcion, sizeof(opcion));
        	write(pipe1[1], &operando1, sizeof(operando1));
        	write(pipe1[1], &operando2, sizeof(operando2));
        	close(pipe1[1]);

		 wait(NULL);
		 
	
	}
	
	printf("\n Termina proceso 2");

	printf("\n Termina proceso 1");

	exit(0);

}
