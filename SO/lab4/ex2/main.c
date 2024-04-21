#include <stdio.h>
#include <unistd.h>
int main()
{
	 int pid = fork();
	 if (pid == 0) {
		 printf("Child process");
		 execl("/bin/ps", "ps", "-u", NULL);
	 } else {
		 printf("Parent process");
         }
}
