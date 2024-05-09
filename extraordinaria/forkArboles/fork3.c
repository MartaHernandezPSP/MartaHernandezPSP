#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() 
{

    pid_t pid, pid1, pid2, pid3, pid4;

    pid = fork();

    if(pid==0)//p2
    {
    
        pid_t pid_hijo_p2 = getpid();
        pid_t pid_abuelo_p2 = getppid(); // PID del abuelo

        printf("PID hijo (P2): %d", pid_hijo_p2);
        
        if (pid_abuelo_p2 != 1)
         {
            printf(" - PID del abuelo: %d\n", pid_abuelo_p2);
         }

        pid1 = fork();
        
        if(pid1==0)//p3
        {
        
            pid_t pid_hijo_p3 = getpid();
            pid_t pid_abuelo_p3 = getppid(); // PID del abuelo (P2)
            
            printf("PID hijo (P3): %d", pid_hijo_p3);
            
            if (pid_abuelo_p3 != 1) 
            {
                printf(" - PID del abuelo: %d\n", pid_abuelo_p3);
            } 

            pid3 = fork();
            
            if(pid3==0)//p5
            {
                pid_t pid_nieto_p5 = getpid();
                pid_t pid_abuelo_nieto_p5 = getppid(); // PID del abuelo (P3)
                
                printf("PID nieto (P5): %d", pid_nieto_p5);
                
                if (pid_abuelo_nieto_p5 != 1) 
                {
                    printf(" - PID del abuelo: %d\n", pid_abuelo_nieto_p5);
                } 
                
                
            }
            else//p3
            {
                wait(NULL);
            }
        }
        else//p2
        {
            pid2 = fork();
        
            if(pid2==0)//p4
            {
            
                pid_t pid_hijo_p4 = getpid();
                pid_t pid_abuelo_p4 = getppid(); // PID del abuelo (P2)
                
                printf("PID hijo (P4): %d", pid_hijo_p4);
                
                
                if (pid_abuelo_p4 != 1) 
                {
                    printf(" - PID del abuelo: %d\n", pid_abuelo_p4);
                } 
                

                pid4 = fork();
            
                if(pid4==0)//p6
                {
                
                    pid_t pid_nieto_p6 = getpid();
                    pid_t pid_abuelo_nieto_p6 = getppid(); // PID del abuelo (P4)
                    
                    
                    printf("PID nieto (P6): %d", pid_nieto_p6);
                    
                    
                    if (pid_abuelo_nieto_p6 != 1) 
                    {
                        printf(" - PID del abuelo: %d\n", pid_abuelo_nieto_p6);
                    } 
                    
                    
                    
                }
                else//p4
                {
                    wait(NULL);
                }
            }
            else//p2
            {
                wait(NULL);
            }
        }
    }
    else//p1
    {
        wait(NULL);
    }

    exit(0);
}
