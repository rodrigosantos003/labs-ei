#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

int i, pid;
int pids[5];

void signal_handler(int signal)
{
    printf("Parent: Handling process #%d with PID=%d\n", i, pids[i]);
}

int main()
{
    signal(SIGUSR2, signal_handler);

    for (i = 0; i < 5; i++)
    {
        pids[i] = fork();
        if (pids[i] == 0)
        {
            printf("Child #%d, PID=%d\n", i, getpid());
            kill(getppid(), SIGUSR2);
            sleep(2);
            printf("Child #%d, PID=%d is exiting\n", i, getpid());
            exit(0);
        }
        sleep(1);
    }
    // sleep(5);
    for (int i = 0; i < 5; i++)
    {
        int pid = wait(NULL);
        printf("Parent: child with PID=%d ended\n", pid);
    }
    return 0;
}
