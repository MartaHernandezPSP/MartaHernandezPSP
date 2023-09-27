#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void main()
{
	pid_t hijo;	
	
	printf("CCC \n");
	
	hijo=fork();
	
	if (hijo == 0)
	{
	   wait(NULL);	
	   printf("AAA\n");
	   printf("\n");
	} 
	else
	{ 
	   printf("BBB \n");
	}
	
	exit(0);
}
