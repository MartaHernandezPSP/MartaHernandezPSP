#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

void manejador(int signal_num) 
{
    if (signal_num == SIGUSR1) 
    {
        time_t current_time;
        struct tm *time_info;

        time(&current_time);
        time_info = localtime(&current_time);

        printf("Señal de alarma recibida a las: %s", asctime(time_info));
    }
}

int main() 
{
    signal(SIGUSR1, manejador);
    int alarma;
    int segundos;
    int i=1;

	printf("¿Cuántas veces quieres recibir la alarma?\n");
	scanf("%d", &alarma);
	
	printf("¿Cada cuantos segundos quieres que se repita?\n");
	scanf("%d", &segundos);
	
		
    while ( i <= alarma) 
    {
        sleep(segundos);
        kill(getpid(), SIGUSR1);
        i++;
    }
    
    printf("Alarma desactivada\n");

    return 0;
}
