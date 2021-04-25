#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t lock;
sem_t empty; 
sem_t full;
int buffer[5];

int in = 0, out = 0;

pthread_t consumers[4];
pthread_t producers[4];


void* producer(void* arg){
	srand(time(NULL));
	int n = *((int *)arg);
	while(1)
	{
		int item = rand()%1000;
		sem_wait(&empty);
		sem_wait(&lock); 
		buffer[in] = item;
		printf("Producer %d: produced item %d\n", n,buffer[in]);
        	in = (in+1)%5;
		sem_post(&lock); 
		sem_post(&full);
		sleep(rand()%3);
	}
}

void* consumer(void * arg) {
	int n = *((int *)arg);
	while(1)
	{
		sem_wait(&full);
		sem_wait(&lock);
		int item = buffer[out];
		printf("Consumer %d: consumed item %d\n",n,item);
        	out = (out+1)%5;
		sem_post(&lock);
		sem_post(&empty); 
		sleep(rand()%3);
	}
}

int main() {
	srand(time(NULL));
	sem_init(&empty,0,5);
	sem_init(&lock, 0, 1);
	sem_init(&full, 0, 0);
	for (int i = 0; i < 4; i++)
	{
		pthread_create(&producers[i], NULL, producer,(void*) &i);
		usleep(15);
	}
	for (int i =0; i < 4; i++)
	{
		pthread_create(&consumers[i], NULL, consumer,(void*) &i);
		usleep(15);
	}
	for (int i = 0; i < 4; i++) {
		pthread_join(producers[i], NULL);
	}
	for (int i =0; i < 4; i++) {
		pthread_join(consumers[i], NULL);
	}
	return 0;
}