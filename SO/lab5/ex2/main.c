#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(){
	sem_unlink("ping");
	sem_unlink("pong");
	sem_t *ping = sem_open("ping", O_CREAT, 0644, 0);
	sem_t *pong = sem_open("pong", O_CREAT, 0644, 1);

	if(fork() == 0){
		while(1){
			sem_wait(ping);
			printf("Pong\n");
			sleep(1);
			sem_post(pong);
		}
	} else{
		while(1){
			sem_wait(pong);
			printf("Ping\n");
			sleep(1);
			sem_post(ping);
		}
	}

	return 0;
}
