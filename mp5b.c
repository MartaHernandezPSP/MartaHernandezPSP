#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
void main()
{

//LA SALIDA QUE PRODUCE ES: AAA BBB CCC BBB o AAA CCC BBB CCC
//SI QUE PUEDEN RPODUCIRSE SALIDAS DIFERENTES

	pid_t pid1, pid2;
	
	printf("AAA \n");
	
	pid1 = fork();
	
	if (pid1==0)
	{
	   printf("BBB \n");
	}
	else
	{
	   pid2 = fork();
	   printf("CCC \n");
	}
	exit(0);
}
