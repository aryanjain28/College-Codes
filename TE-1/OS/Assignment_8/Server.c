#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <stdio.h> 

int main(){
 
	key_t key = 5678; 
 
	int shmid = shmget(key,1024,0666|IPC_CREAT); 

	char *str = (char*) shmat(shmid,(void*)0,0); 

	printf("Write Data : ");

	scanf("%s", str);

	printf("Data written in memory: %s\n",str); 
} 
