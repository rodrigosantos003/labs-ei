#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MAXNUMBER 5

int main(){
	int pid;

	for(int i= 0; i < MAXNUMBER;i++){
		pid = fork();
		if(pid ==0){
			printf("Child Process (PID=%d , PPID=%d)\n",getpid(),getppid());
			printf("Child PID =%d exiting!\n",getpid());
			exit(0);
		}
	}

	sleep(1);
	printf("Parent Process(PID=%d)\n",getpid());
	int temp;

	for(int i= 0 ; i < MAXNUMBER;i++){
		int cpid = wait(&temp);
		printf("A child has exited: CPID=%d\n",cpid);
	}
	
	return 0;
	
}
