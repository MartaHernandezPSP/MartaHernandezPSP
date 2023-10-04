#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() 
{

    pid_t p2,p3,p4,pid;  
    
    pid = getpid();
    	   
    	  printf("Soy el p1 ");
    	  
    	  if( pid%2 == 0)
    	  {
    	     printf("PID: %d y PPID: %d \n",pid, getppid());
    	  }
    	  else
    	  {
    	    printf("PID: %d \n",pid);
    	  }

    p2 = fork();
    
	if(p2 == 0)//soy el p2
	{
		printf("Soy el p2 ");
		pid = getpid();
		
		if( pid%2 == 0)
    	  {
    	     printf("PID: %d y PPID: %d \n",pid, getppid());
    	  }
    	  else
    	  {
    	    printf("PID: %d \n",pid);
    	  }
	
	}
	else//soy el p1
	{
		p3 = fork();
		
		if( p3 == 0)//soy el p3
		{
			printf("Soy el p3 ");
				pid = getpid();
			
				if( pid%2 == 0)
				  {
					 printf("PID: %d y PPID: %d \n",pid, getppid());
				  }
				  else
				  {
					printf("PID: %d \n",pid);
				  }
				  
			p4 = fork();
			
			if(p4 == 0)//soy el p4
			{
				printf("Soy el p4 ");
				pid = getpid();
				
				if( pid%2 == 0)
				  {
					 printf("PID: %d y PPID: %d \n",pid, getppid());
				  }
				  else
				  {
					printf("PID: %d \n",pid);
				  }
			
			
			}
			else//soy el p3
			{
				wait(NULL);
				
			}
			
		
		}
		else//soy el p1
		{
			wait(NULL);
			wait(NULL);
			
		}
		
	}

    

   exit(0);
}
