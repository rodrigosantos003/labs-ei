#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <pthread.h> 
#include <semaphore.h> 
#include <fcntl.h>

int main()
{
 // Create shared memory map
 int size = 64;
 int protection = PROT_READ | PROT_WRITE;
 int visibility = MAP_ANONYMOUS | MAP_SHARED;
 void *shmem = mmap(NULL, size, protection, visibility, 0, 0);
 
  sem_unlink("mymutex");
  sem_t *mutex = sem_open("mymutex", O_CREAT, 0644, 1);
 

 int cpid = fork();
 if (cpid == 0) {
	 printf("Child process!\n");
	 sem_wait(mutex);
	 printf("shmem=%s", (char*) shmem);
	 exit(0);
 }
 else {
	 printf("Parent process!\n");
         sem_wait(mutex);
	 char *msg = "Hello from child process..\n";
	 sleep(1);
	 strcpy(shmem, msg);
	 sem_post(mutex);
	 
 }

 return (EXIT_SUCCESS);
}

