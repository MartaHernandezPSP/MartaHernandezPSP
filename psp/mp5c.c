#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
void main()
{
	pid_t pid1, pid2;
	
	
	
	pid1 = fork();//hijo
	
	if (pid1==0)
	{
	   printf("BBB \n");
	}
	else
	{
	   pid2 = fork();//hijo
	   wait(NULL);
	   
	   if( pid2 == 0)
	   {
	      wait(NULL);
	      printf("CCC \n");
	   }
	   else
	   {
	   	wait(NULL);
	   	wait(NULL);
	   	printf("AAA \n");
	   }
	}
	exit(0);
}
