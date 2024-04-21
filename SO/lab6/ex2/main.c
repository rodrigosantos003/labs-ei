#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/mman.h>
#include <semaphore.h>
#include <fcntl.h>

int main()
{
	// Workers
	int num_workers = 5;
	int pids[num_workers];

	int size = 64;
	int protection = PROT_READ | PROT_WRITE;
	int visibility = MAP_ANONYMOUS | MAP_SHARED;
	void *shmem = mmap(NULL, size, protection, visibility, 0, 0);

	sem_unlink("job_ready");
	sem_unlink("job_done");

	sem_t *job_ready = sem_open("job_ready", O_CREAT, 0644, 0);
	sem_t *job_done = sem_open("job_done", O_CREAT, 0644, 1);

	// Fork worker processes
	for (int i=0; i<num_workers; i++) {
		pids[i] = fork();
		if (pids[i] == 0) {
			printf("Worker process #%d!\n", i);
			while (1) {
				sem_wait(job_ready);
				printf("ID: %d, Tamanho: %ld, MSG: %s\n", getpid(), strlen(shmem), (char*) shmem);
				sem_post(job_done);
	 		}
			exit(0);
		}
	 }

	 // Parent process
	 printf("Parent process!\n");
	 char *s[] = {"Hello", "AAA", "dsnhfpdjpsdlç", "ncklsancs", "asponcksamklasdnbcflds"};

	 for(int x = 0; x < 5; x++){
		 sem_wait(job_done);
		 strcpy(shmem, s[x]);
		 sleep(1);
		 sem_post(job_ready);
	 }

	 sleep(2);

	 // Kill worker processes
	 for (int i=0; i<num_workers; i++) {
		 printf("Killing %d\n", pids[i]);
		 kill(pids[i], SIGKILL);
	 }

	 return (EXIT_SUCCESS);
}
