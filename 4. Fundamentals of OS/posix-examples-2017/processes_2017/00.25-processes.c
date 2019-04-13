#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char **argv) {


    sleep(10);

	pid_t pid = fork();
	
	if (pid == 0) {
		printf("Hello from child! %d \n", argc);
		
		execl("/bin/cat", "/bin/cat", "00-processes.c", NULL);
		
		printf("Bye from child! %d \n", argc);
	} else if (pid > 0) {
		printf("Hello from parent %d !\n", argc);
    	sleep(30);

	} else {
		perror("fork");
		return 1;
	}

	return 0;
}
