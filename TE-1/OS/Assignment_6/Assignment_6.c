#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

#define N 5
#define THINKING 0
#define HUNGRY 1
#define EATING 2
#define LEFT (philosopherNumber + 1)%N
#define RIGHT (philosopherNumber + 4)%N


pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int state[10];
sem_t S[10];

void * philosopher(void * number);
void takeFork(int);
void putFork(int);
void test(int);

int main(){
	pthread_t P[10];

	for(int i=0; i<N; i++)
		sem_init(&S[i],0,0);



	for(int i=0; i<N; i++){
		state[i] = THINKING;
		printf("\nPhilosopher %d -- THINKING", i);
		pthread_create(&P[i], NULL, philosopher, &i);	
	}
	
	
	for(int i=0; i<N; i++)
		pthread_join(P[i], NULL);


}

void * philosopher(void * number){
	
	int philosopherNumber = *(int *)number;
	
	while(1){
		takeFork(philosopherNumber);
		sleep(1);
		putFork(philosopherNumber);
	}
}

void takeFork(int philosopherNumber){
	pthread_mutex_lock(&mutex);
	state[philosopherNumber] = HUNGRY;
	printf("\nPhilosopher %d -- HUNGRY", philosopherNumber);	
	test(philosopherNumber);
	pthread_mutex_unlock(&mutex);
	sem_wait(&S[philosopherNumber]);
	sleep(1);
}

void putFork(int philosopherNumber){
	pthread_mutex_lock(&mutex);
	printf("\nPhilosopher %d -- THINKING", philosopherNumber);
	state[philosopherNumber] = THINKING;
	test(LEFT);
	test(RIGHT);
	pthread_mutex_unlock(&mutex);
	sleep(1);
}

void test(int philosopherNumber){
	if(state[philosopherNumber] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING){
		state[philosopherNumber] = EATING;
		printf("\nPhilosopher %d -- EATING", philosopherNumber);
		sem_post(&S[philosopherNumber]);	
	}
	sleep(1);
}





