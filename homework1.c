#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	int fd[2];
	char buffer[10];
	pid_t pid;
	int state;

	if(pipe(fd) == -1) {
		printf("pipe() errov\n");
		exit(1);
	}

	pid = fork();
	if(pid == -1) {
		printf("fork() error!\n");
		exit(1);
	}

	if(pid == 0) { // child
		printf("hello\n");
		write(fd[1], "1", 10);
	}
	else { // parent
		read(fd[0], buffer, 10);
		printf("goodbye\n");
	}

	return 0;
}
