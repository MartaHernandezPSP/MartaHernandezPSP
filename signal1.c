#include <stdio.h> 
#include <signal.h> 
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

	void manejador(int signal_num) 
	{
	    if (signal_num == SIGINT) 
	    {
		time_t current_time;
		struct tm *time_info;

		time(&current_time);
		time_info = localtime(&current_time);

		printf("\nProceso %d finalizado. Fecha y hora de finalización: %s", getpid(), asctime(time_info));
		exit(EXIT_SUCCESS);
	    }
	}

  /***************************************************/
  
	int main() 
	{
	    int pid;
	    time_t hora;
	    char *fecha;
	    time(&hora);
	    fecha = ctime(&hora);

	    pid = getpid();
	    
	    // Corregir la línea de impresión
	    printf("Inicio del proceso %d : %s", pid, fecha);

	    signal(SIGINT, manejador);

	    while (1) 
	    {
		
		sleep(1);
	    }

	    return 0; 
	}
