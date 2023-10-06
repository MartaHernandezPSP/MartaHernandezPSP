#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() 
{

	pid_t p2,p3,p4,p5,acumulado,pid;
	acumulado = getpid();
	printf("Variable acumulado: %d \n",acumulado);
	
	p2=fork();
	
	if(p2 == 0)//p2
	{
		pid=getpid();
		if( pid%2 == 0)
    	  {
    	     printf("Soy el P2 variable acumulado: %d \n",acumulado+10);
    	  }
    	  else
    	  {
    	    printf("Soy el P2 variable acumulado: %d \n",acumulado-100);
    	  }
    	  
		p4=fork();

		if(p4 == 0)//p4
		{
			pid=getpid();
			if( pid%2 == 0)
			  {
			     printf("Soy el P4 variable acumulado: %d \n",acumulado+10);
			  }
			  else
			  {
			    printf("Soy el P4 variable acumulado: %d \n",acumulado-100);
			  }
		}
		else//p2
		{
			wait(NULL);
		}
	
	}
	else//p1
	{
		p3=fork();
		
		if(p3 == 0)//p3
		{
			pid=getpid();
			if( pid%2 == 0)
			  {
			     printf("Soy el P3 variable acumulado: %d \n",acumulado+10);
			  }
			  else
			  {
			    printf("Soy el P3 variable acumulado: %d \n",acumulado-100);
			  }
			p5=fork();
			
			if(p5 == 0)//p5
			{
				pid=getpid();
			if( pid%2 == 0)
			  {
			     printf("Soy el P5 variable acumulado: %d \n",acumulado+10);
			  }
			  else
			  {
			    printf("Soy el P5 variable acumulado: %d \n",acumulado-100);
			  }
			}
			else//p3
			{
				wait(NULL);
			}
		}
		else//p1
		{
			wait(NULL);
		}
		
	 	wait(NULL);
	}
	

exit(0);
}
