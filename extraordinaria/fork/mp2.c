#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() 
{
    pid_t pid, pid2;
    pid_t padre, hijo, nieto;

    padre = getpid();

    pid = fork();

    if (pid == 0) // hijo
    { 
    
        hijo = getpid();
        pid2 = fork();

        if (pid2 == 0) // nieto
        { 
            printf("Proceso P3\n");
            printf("Pid P3: %d , Pid P2: %d \n", getpid(), hijo);
        } 
        else // hijo
        { 
            wait(NULL);
            printf("Proceso P2\n");
            printf("Pid P2: %d , Pid P1: %d \n", getpid(), padre);
        }
        
    } 
    else// padre
    { 
    
        wait(NULL);
        printf("Proceso P1\n");
        printf("Pid P1: %d y Pid P2: %d \n", getpid(), pid);
    }

    exit(0);
    
}
