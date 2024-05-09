#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() 
{

	pid_t p2,p3,p4,suma;
	
	suma = getpid() + getppid();
	
	printf("Soy p1. PID: %d PPID: %d .La suma es: %d \n",getpid(),getppid(),suma);

	p2=fork();
	
	if(p2 == 0)//soy p2
	{
		suma = getpid() + getppid();
	
		printf("Soy p2. PID: %d PPID: %d .La suma es: %d \n",getpid(),getppid(),suma);

		p3=fork();
		
		if(p3 == 0)//soy p3
		{
			suma = getpid() + getppid();
	
			printf("Soy p3. PID: %d PPID: %d .La suma es: %d \n",getpid(),getppid(),suma);

			p4=fork();
			
			if(p4 == 0)//soy p4
			{
				suma = getpid() + getppid();
	
				printf("Soy p4. PID: %d PPID: %d .La suma es: %d \n",getpid(),getppid(),suma);
				
			}
			else//soy p3
			{
				wait(NULL);
			}
		
		}
		else//soy p2
		{
			wait(NULL);
		}
	
	}
	else//soy p1
	{
		wait(NULL);
	}

exit(0);

}
