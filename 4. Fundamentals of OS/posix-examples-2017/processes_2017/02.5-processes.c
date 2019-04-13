#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv) {
	printf("Hello world!\n");

	char* args[] = {
		"/bin/ls",
		"-l",
		NULL
	};

    pid_t pid = fork();
    
    if (pid == 0 ) 
    {
	    execl("./test1", NULL, NULL);
    	perror("execv");
        printf("Goodbye world!\n");
	}
	else
	{
	    printf("Goodbye world from parent!\n");
        printf("\n");
	}
	return 0;
}
