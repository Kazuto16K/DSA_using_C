#include<semaphore.h>
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<pthread.h>

sem_t mutex;

int prod=0;
int total=0;

void *producer(void *p1){
	while(1){
		sleep(1);
		sem_wait(&mutex);
		printf("I am Producer, Producing Item; No of Items NOW: %d\n",++prod);
		total++;
		printf("Total Items now: %d\n\n",total);
		sem_post(&mutex);
	}
	pthread_exit(NULL);
}

void *consumer(void *p2){
	while(1){
		sleep(2);
		sem_wait(&mutex);
		printf("I am Consumer, Consuming Item; No of Items NOW: %d\n",--prod);
		total--;
		printf("Total Items now: %d\n\n",total);
		sem_post(&mutex);
	}
	pthread_exit(NULL);
}

int main(){
	sem_init(&mutex,0,1);
	pthread_t th[2];
	int ch1,ch2;
	ch1=pthread_create(&th[0],NULL,producer,NULL);
	ch2=pthread_create(&th[1],NULL,consumer,NULL);
	
	pthread_join(th[0],NULL);
	pthread_join(th[1],NULL);
}
