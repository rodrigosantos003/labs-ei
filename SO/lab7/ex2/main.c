#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

void signal_handler(int signal)
{
 	printf("Got signal %d..\n", signal);
}

int main()
{
	 signal(SIGUSR1, signal_handler);
	 signal(SIGUSR2, signal_handler);

	 int pid = fork();
	 if (pid == 0) {
		 printf("Hello from child!\n");
		 while(1){
			}
		 
		 exit(0);
	 } else {
		 printf("Hello from parent!\n");
		 kill(pid, SIGUSR1);
		 sleep(1);
		 kill(pid, SIGUSR2);
		 sleep(1);
		 kill(pid, SIGINT);
		 sleep(1);
		 kill(pid, SIGKILL);
		 wait(NULL);
	 }
 	return 0;
}
