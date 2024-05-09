#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() 
{

	pid_t p2,p3,p4,p5,p6,suma, pidabuelo1,pidabuelo2;
	
	pidabuelo1 = getpid();
	printf("Soy el P1, mi pid es: %d \n",pidabuelo1);

	p2 = fork();
	
	if( p2 ==0 )//p2
	{
		pidabuelo2 = getpid();
		printf("Soy el P2, mi pid es: %d \n",pidabuelo2);
		p3 = fork();
		
		if(p3 == 0)//p3
		{
			printf("Soy el P3, mi pid es: %d y mi abuelo: %d \n",getpid(),pidabuelo1);
			p5 =fork();
			
			if(p5 == 0)//p5
			{
				printf("Soy el P5, mi pid es: %d y mi abuelo: %d \n",getpid(),pidabuelo2);
			}
			else//p3
			{
				wait(NULL);
			}
		
		}
		else//p2
		{
			p4 = fork();
			
			if(p4 == 0)//p4
			{
				printf("Soy el P4, mi pid es: %d y mi abuelo: %d \n",getpid(),pidabuelo1);
				p6=fork();
				
				if(p6 == 0)//p6
				{
					printf("Soy el P6, mi pid es: %d y mi abuelo: %d \n",getpid(),pidabuelo2);
				}
				else//p4
				{
					wait(NULL);
				}
			}
			else//p2
			{
				wait(NULL);
				
			}
			wait(NULL);
		}
	
	}
	else//p1
	{
		wait(NULL);
	}

exit(0);
}
