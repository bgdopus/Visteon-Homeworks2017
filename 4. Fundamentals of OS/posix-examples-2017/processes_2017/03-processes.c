#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>

void do_parent(int pipes[])
{
    int c;
    int rc;
    close (pipes[0]);
    while ((c =getchar()) > 0)
    {
        printf("Read forn stdin: %c\n", c);
        rc = write(pipes[1], &c, 1);
    }
   close(pipes[1]);
   return ;
}

void do_child(int pipes[])
{
    int c;
    int rc;
    close (pipes[1]);
    while ((rc =read(pipes[0], &c, 1)) > 0)
    {
        putchar(c);
        write(pipes[0], &c, 1);
    }
   close(pipes[0]);
   return;
}

int main(int argc, char **argv) {

    int pipes[2];
  

    int rc = pipe(pipes);
    
    if (-1 == rc)
    {
        perror("pipe");
      return -1;
     }
        
	pid_t pid = fork();

    
	if (pid == 0) {
		printf("Hello from child! PID=%d \n", getpid());
        do_child(pipes);
	} else if (pid > 0) {
		printf("Hello from parent! PID=%d \n", getpid());
		do_parent(pipes);
	} else {
		perror("fork");
		return 1;
	}

	return 0;
}
