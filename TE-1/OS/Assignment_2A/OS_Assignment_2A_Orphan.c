#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
	pid_t pid;
	pid = fork();

	if (pid == 0){
		int oldParent = getppid();
		sleep(3);
		printf("\n\nChild process executing...\n");
		printf("Child process ID : %d.\n", getpid());
		printf("Old parent : %d.\n", oldParent);
		printf("New parent : %d.\n\n", getppid());		

		/*Orphan process is immediately adopted by the special init system process. 
		This operation is called re-parenting and occurs automatically.*/
	}
	else if (pid > 0){
		printf("Parent process executing...\n");
		printf("Parent process ID : %d.\n", getpid());
		printf("Child process ID of parent : %d.\n", pid);
		exit(0);
	}
	else {
		printf("ERROR!!\n\n");	
	}
}
