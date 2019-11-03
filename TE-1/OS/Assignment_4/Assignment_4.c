#include<semaphore.h>
#include<pthread.h>
#include<stdio.h>

#define SIZE 5
#define NOP 5
#define NOC 5

void * producer(void * args);
void * consumer(void * args);

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
sem_t empty;
sem_t full;

int buffer[100], count=0;

int main(){
	
	pthread_t p1[10], p2[10];
	sem_init(&empty, 0, SIZE);
	sem_init(&full,  0, 0);

	for(int i=0; i<NOP; i++){
		int k = i+1;
		pthread_create(&p1[i], NULL, producer, &k);
	}

	for(int i=0; i<NOC; i++){
		int k = i+1;
		pthread_create(&p2[i], NULL, consumer, &k);
	}

	for(int i=0; i<NOP; i++)
		pthread_join(p1[i], NULL);

	for(int i=0; i<NOC; i++)
		pthread_join(p2[i], NULL);

	printf("\n\n");

}

void * producer(void * args){
	int num = *(int *) args;
	sem_wait(&empty);
	pthread_mutex_lock(&mutex);

	buffer[count] = num;
	count++;
	printf("\nProduced : %d", buffer[count-1]);

	pthread_mutex_unlock(&mutex);
	sem_post(&full);
}

void * consumer(void * args){
	int num = *(int *) args;
	sem_wait(&full);
	pthread_mutex_lock(&mutex);

	num = buffer[count-1];
	count--;
	printf("\nConsumed : %d", num);

	pthread_mutex_unlock(&mutex);
	sem_post(&empty);
}
