#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() 
{

    pid_t hijo;  
    
    
    hijo = fork();
  
    if(hijo == 0)  //hijo
    {
    	
    	printf("Soy el hijo, mi nombre es: MARTA \n");

    	
    }
    else   //padre
    {
    	wait(NULL);  //se para para que termine el padre primero
    	printf("Soy el padre mi PID es %d y PID hijo %d \n", getpid(), getppid());
    }
  
  
   exit(0);
}
