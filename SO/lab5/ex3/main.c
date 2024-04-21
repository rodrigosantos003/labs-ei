#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(){
	sem_unlink("ping");
	sem_unlink("pong1");
	sem_unlink("pong2");
	sem_t *ping = sem_open("ping", O_CREAT, 0644, 0);
	sem_t *pong1 = sem_open("pong1", O_CREAT, 0644, 0);
	sem_t *pong2 = sem_open("pong2", O_CREAT, 0644, 1);

	if(fork() == 0){
		while(1){
			sem_wait(ping);
			printf("Pong1\n");
			sleep(1);
			sem_post(pong1);
		}
	}

	if(fork() == 0){
		while(1){
			sem_wait(pong1);
			printf("Pong2\n");
			sleep(1);
			sem_post(pong2);
		}
	}

	while(1){
		sem_wait(pong2);
		printf("Ping\n");
		sleep(1);
		sem_post(ping);
	}

	return 0;
}
