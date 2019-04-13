#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char **argv) {

	pid_t pid ;
	
	fork();
	fork();
    fork();
	/*
	if (pid == 0) {
		printf("Hello from child! pid = %d Process id %d\n ", pid, getpid());
		
	} else if (pid > 0) {
		sleep(10);
		printf("Hello from parent!  pid = %d Process id %d\n ", pid, getpid());
	} else {
		perror("fork");
		return 1;
	}
*/

    printf("Hello\n");
    sleep(5);
	return 0;
}
