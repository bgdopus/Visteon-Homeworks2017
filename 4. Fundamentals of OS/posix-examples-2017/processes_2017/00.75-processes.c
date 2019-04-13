#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char **argv) {

    int status;
	pid_t pid = fork();
	pid_t wait_pid;
	if (pid == 0) {
		printf("Hello from child! pid is: %d\n", getpid());
		sleep(20);
		printf("Child exits\n");
	} else if (pid > 0) {
		printf("Hello from parent! My Pid is: %d, My child's pid is %d \n", getpid(), pid);
		//wait_pid=wait(&status);
		//printf("Process waited is: %d\n", wait_pid);
		sleep(10);
		printf("Parent exits\n");
	} else {
		perror("fork");
		return 1;
	}

    //exit(0);
	return 0;
}
