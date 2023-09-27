#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void main()
{

	//LA SALIDA DE ESTE CODIGO ES: CCC AAA BBB
	//PODRIA PRODUCIRSE OTRA SALIDA DEPENDIENDO DEL VALOR DEL FORK 
	//O DEL PROCESO QUE QUIERA EJECUTAR EL SISTEMA ANTES
	
	printf("CCC \n");

	
	if (fork() != 0)
	{
	
	   printf("AAA\n");

	} 
	else
	{ 
	   printf("BBB \n");
	}
	
	exit(0);s
}
