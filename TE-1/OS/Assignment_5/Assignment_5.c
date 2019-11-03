#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

#define NOR 5
#define NOW 5

void *reader(void* args);
void *writer(void* args);

pthread_mutex_t writerBlock = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t readerBlock = PTHREAD_MUTEX_INITIALIZER;

int readerCount = 0;
int data = 0;

int main(){
	
	pthread_t p1[10], p2[10];

	for(int i=0; i<NOW; i++)
		pthread_create(&p1[i], NULL, writer, &i);

	for(int i=0; i<NOR; i++)
		pthread_create(&p2[i], NULL, reader, &i);

	for(int i=0; i<NOW; i++)
		pthread_join(p1[i], NULL);

	for(int i=0; i<NOR; i++)
		pthread_join(p2[i], NULL);

	printf("\n\n");

}

void *reader(void* args){
	printf("\nReader is trying to enter!");
	
	pthread_mutex_lock(&readerBlock);
	printf("\nReader has entered!");
	readerCount+=1;
	if(readerCount >= 1)
		pthread_mutex_lock(&writerBlock);
	pthread_mutex_unlock(&readerBlock);

	pthread_mutex_lock(&readerBlock);
	readerCount-=1;
	printf("\nReader has left!");
	if(readerCount==0){
		printf("\n\n\nReadercount is ZERO writer can enter!\n\n");
		pthread_mutex_unlock(&writerBlock);
	}
	pthread_mutex_unlock(&readerBlock);
}

void *writer(void* args){
	printf("\nWriter is trying to enter!");
	pthread_mutex_lock(&writerBlock);
	pthread_mutex_lock(&readerBlock);
	data++;
	printf("\nWriter has entered!\tDATA : %d", data);	
	pthread_mutex_unlock(&writerBlock);
	printf("\nWriter has left!");
	pthread_mutex_unlock(&readerBlock);
}
