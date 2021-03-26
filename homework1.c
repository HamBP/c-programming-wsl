#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 5

int main(int argc, char** argv) {
	int fd[2];
	char buffer[BUFFER_SIZE];
	pid_t pid;

	if(pipe(fd) == -1) {
		printf("pipe() error!\n");
		exit(1);
	}
	
	pid = fork();
	if(pid == -1) {
		printf("fork() error!\n");
		exit(1);
	}
	// child
	if(pid == 0) {
		printf("hello\n");
		write(fd[1], "", BUFFER_SIZE);
		close(fd[1]);
	}
	// parent
	else {
		read(fd[0], buffer, BUFFER_SIZE);
		printf("goodbye\n");
		close(fd[0]);
	}

	return 0;
}
