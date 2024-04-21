#include <stdio.h>
#include <unistd.h>
int main()
{
	 int pid = fork();
	  if (pid == 0) {
		  printf("Child Porcess!");
	  } else {
		  sleep(1);
		  printf("Parent Process (child pid=%d)!", pid);
	  }
	  
	  
}
