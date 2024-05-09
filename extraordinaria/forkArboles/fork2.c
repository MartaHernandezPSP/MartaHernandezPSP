#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() 
{
    int fd[2];
    pid_t pid, pid1, pid2;

    pipe(fd);

    pid = fork();

    if (pid == 0) // hijo
    { 
    
        pid1 = fork();

        if (pid1 == 0) // hijo1
        { 
        
            pid2 = fork();

            if (pid2 == 0) // hijo2
            { 
            
                pid = getpid();
                pid1 = getppid();
                printf("PID: %d - PID del padre: %d - Suma de PIDs: %d\n", pid, pid1, pid + pid1);
            } 
            else // hijo1
            { 
            
                pid = getpid();
                pid1 = getppid();
                printf("PID: %d - PID del padre: %d - Suma de PIDs: %d\n", pid, pid1, pid + pid1);
                wait(NULL); // Esperar a que termine el hijo2
            }
            
        } 
        else // hijo
        { 
        
            pid = getpid();
            pid1 = getppid();
            printf("PID: %d - PID del padre: %d - Suma de PIDs: %d\n", pid, pid1, pid + pid1);
            wait(NULL); // Esperar a que termine el hijo1
            
        }
        
    } 
    else // padre
    { 
    
        pid = getpid();
        printf("PID: %d\n", pid);
        wait(NULL); // Esperar a que termine el hijo
        
    }

    exit(0);
}
