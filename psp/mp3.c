#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() 
{

    pid_t hijo,hijo1;  
    
    
    hijo = fork();
    
    
  
    if(hijo == 0)  //hijo
    {
    	printf("Soy un hijo. Voy a dormir 10 segundos \n");
    	sleep(10);
    	printf("Despierto \n");

    }
    
    else   //padre
    {
      	hijo1=fork();
        
	    if(hijo1 == 0)//hijo2
	    {
		   wait(NULL);
		   printf("Soy un hijo. Mi PID es %d y PID padre es %d \n", getpid(), getppid());
		
	    }
	    else
	    {    
    		wait(NULL);
    	        wait(NULL);  //se para para que termine el padre primero
    	        printf("Soy el padre \n");
	    }
	    
	    
	
    }
  
  
   exit(0);
}
