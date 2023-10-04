#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() 
{

	pid_t hijo,nieto,padre,pid,ppid,suma;
	
	padre = fork();

	if( padre == 0)//padre
    	 {
    	     hijo = fork();
    	     
    	      if(hijo == 0)//hijo
    	      {
    	     	 nieto = fork();
    	     	
	    	     	if(nieto == 0)//nieto
	    	     	{
	    	     		pid = getpid();
	    	     		ppid = getppid();
	    	     		suma = pid + ppid;
	    	     		
	    	     		printf("Nieto. Suma: %d \n",suma);
	    	     	
	    	     	}
	    	     	else//hijo
	    	     	{
	    	     		wait(NULL);
	    	     		pid = getpid();
	    	     		ppid = getppid();
	    	     		suma = pid + ppid;
	    	     		
	    	     		printf("Hijo. Suma: %d \n",suma);
	    	     	
	    	     	}
    	     	

    	      }
    	      else//padre
    	      {
    	      	wait(NULL);
    	      	wait(NULL);
	    	     		pid = getpid();
	    	     		ppid = getppid();
	    	     		suma = pid + ppid;
	    	     		
	    	     		printf("Padre. Suma: %d \n",suma);
    	      
    	      }
      	     
    	 }
    	 else//abuelo
    	 {
    	   
    	   wait(NULL);
    	   wait(NULL);
    	   wait(NULL);
	    	     		pid = getpid();
	    	     		ppid = getppid();
	    	     		suma = pid + ppid;
	    	     		
	    	     		printf("Abuelo. Suma: %d \n",suma); 
    	    
    	    
    	 }


exit(0);

}
