#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
	int pid = fork();

	if(pid == 0){
		printf("Child process (PID=%d, PPID=%d)\n", getpid(), getppid());
		sleep(2);
		printf("Child PID=%d exiting\n", getpid());
		exit(0);
	} else{
		printf("Parent process (PID=%d, CPID=%d)\n", getpid(), pid);
		int tmp;
		int child_pid = wait(&tmp);
		printf("A child has exited: CPID=%d\n", child_pid);
	}

	return 0;
}
