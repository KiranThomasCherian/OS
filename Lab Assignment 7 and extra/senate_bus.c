#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>

#define MAX_RIDERS 50

sem_t mutex;	
sem_t sem_riders; 
sem_t sem_bus;   //bus
sem_t sem_depart;    //all aboard
int waiting = 0;


void *passenger(void *arg){
	while(1){

		sem_wait(&sem_riders);
		sem_wait(&mutex);		
		waiting = waiting + 1;
		printf("inwait\n");				
		printf("[waiting] passengers= %d \n",waiting);
		sem_post(&mutex); 		
		sleep(1);
		sem_wait(&sem_bus);						
		sem_post(&sem_riders);
		
		printf("[bus arrived] boarding= %d \n",waiting--);					
		sleep(2);
		if(waiting ==0){
			sem_post(&sem_depart);
		}else{
			sem_post(&sem_bus);
		}	
	}
}

void * bus(void *arg){	
	while(1){					
		sem_wait(&mutex);		
		if(waiting >0){
		sem_post(&sem_bus);
		sem_wait(&sem_depart);
		}
		printf("[depart] waiting: %d \n",waiting);
		sem_post(&mutex);				
		sleep(3);
	}
}


void main(int argc, char * argv[]){
	pthread_t  pid[MAX_RIDERS];
	pthread_t b;
	sem_init(&mutex,0,1);
	sem_init(&sem_riders,0,20);
	sem_init(&sem_bus,0,0);
	sem_init(&sem_depart,0,0);
	pthread_create(&b,NULL,bus,NULL);
	for(int i=0;i< MAX_RIDERS ;i++){
		pthread_create(&pid[i],NULL,passenger,NULL);
	}
	//pthread_create(&b1,NULL,bus,NULL);
	//pthread_create(&t1,NULL,bus,(void*)&i);
	pthread_join(b,NULL);
}
