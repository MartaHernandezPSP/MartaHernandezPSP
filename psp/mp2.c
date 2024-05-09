#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


void main() 
{

    pid_t padre,hijo,pid,ppid;  
    
    
    padre = fork();
  
    if(padre == 0)  //padre
    {
    	hijo=fork();
    	
    	   if(hijo==0)
    	   {
    	   	printf("Soy el hijo pid = %d ppid= %d soy P1 \n",getpid(),getppid());
    	   }
    	   else
    	   {
    	   	wait(NULL);
    	   	printf("Soy el padre pid = %d ppid= %d soy P2\n",getpid(),getppid());
    	   }
    	   
    	
    }
    else   //abuelo
    {
    	wait(NULL);  //se para para que termine el padre primero
    	printf("Soy el abuelo pid = %d ppid= %d soy P3\n",getpid(),getppid());
    }
  
  
   exit(0);
}
