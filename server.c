
#include<stdio.h>
#include<signal.h>
#include <unistd.h>

void handle(int sig)
{
	// if (sig == SIGUSR1)
    //     printf("0");
    // else
        printf("1");
}

int main()
{
    pid_t iPid = getpid(); /* Process gets its id.*/
    printf("iPid : %d \n", iPid);
    signal(SIGUSR1, handle);
    signal(SIGUSR2, handle);
    while (1)
    {
        
        sleep(1);
    }

	return (0);
}