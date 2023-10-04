#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() 
{

    pid_t hijo,hijo1,nieto,pid;  

    hijo = fork();
    
  
    if(hijo == 0)//hijo
    {
    	nieto = fork();

	if(nieto == 0 )//nieto
    	{
    	  printf("Soy el nieto ");
    	  
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
    	else//hijo
    	{
    	  
    	  printf("Soy el hijo1 ");
    	   wait(NULL);
    	   wait(NULL);
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

    	
    }
    else   //padre
    {
        wait(NULL);
    	hijo1 = fork();
    	    	
    	if(hijo1 == 0 )//hijo1
    	{
    	   wait(NULL);
    	   printf("Soy el hijo2 ");
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
    	else//padre
    	{
    	   wait(NULL);
    	   wait(NULL);
    	   wait(NULL);
    	   pid = getpid();
    	   
    	   printf("Soy el padre ");
    	  
    	  if( pid%2 == 0)
    	  {
    	     printf("PID: %d y PPID: %d \n",pid, getppid());
    	  }
    	  else
    	  {
    	    printf("PID: %d \n",pid);
    	  }
    	
    	}
    }
   exit(0);
}
