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

        printf("Tiempo transcurrido: %s", asctime(time_info));
    }
}

int main() 
{
    signal(SIGUSR1, manejador);

    while (1) 
    {
        sleep(5);
        kill(getpid(), SIGUSR1);
    }

    return 0;
}
