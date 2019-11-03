#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
	pid_t pid;
	pid = fork();

	if (pid == 0){
		printf("This is the  child process! %d\n\n", getpid());
		exit(0);
	}
	else if (pid > 0){
		printf("This is the  parent process! %d\n\n", getpid());
		sleep(2);
	}
	else {
		printf("ERROR!!\n\n");	
	}
	execl("/bin/ps", "px aux", NULL);
}
