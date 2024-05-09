#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() 
{
    pid_t pid,pid1,pid2;

    pid=fork();

    if(pid==0)//hijo
    {
        pid1 = getpid();
        
        printf("hijo \n");
        
        if (pid1 % 2 == 0) 
        {
            printf("PID hijo : %d - PID del padre: %d\n", pid1, getppid());
        } 
        else 
        {
            printf("PID hijo : %d\n", pid1);
        }
    }
    else//padre
    {
        pid1=fork();
        
        if(pid1==0)//hijo1
        {
            pid2=fork();
            
            if(pid2==0)//hijo2
            {
            
            	printf("hijo 2 \n");
            	
                pid = getpid();
                
                if (pid % 2 == 0) 
                {
                    printf("PID hijo 2: %d - PID del hijo 1: %d\n", pid, getppid());
                } 
                else 
                {
                    printf("PID hijo 2: %d\n", pid);
                }
                
            }
            else//hijo1
            {
            	wait(NULL);
            	
            	printf("hijo 1 \n");
            	
                pid = getpid();
                if (pid % 2 == 0) 
                {
                    printf("PID hijo 1: %d - PID del padre: %d\n", pid, getppid());
                } 
                else 
                {
                    printf("PID hijo 1: %d\n", pid);
                }
            }
        }
        else//padre
        {
        
            wait(NULL);
            wait(NULL);
            
            pid = getpid();
            
            printf("Padre \n");
            
            if (pid % 2 == 0) 
            {
                printf("PID padre: %d ", pid);
            } 
            else 
            {
                printf("PID padre: %d\n", pid);
            }
            
            
        }
    }

    exit(0);
}
