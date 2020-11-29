#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include<time.h>
#include<unistd.h>
#define BUFFERSIZE 8
int counter=0;
int in=0;
int out=0;
int buffer[BUFFERSIZE];
int cc=0;
void *producer(void *q)
{   
        while(1){
        while(counter==BUFFERSIZE);
        for(int i=0;i<600000;i++); 	//to simulate production 
        buffer[in] = cc++;
        counter++;
        printf("Produced Item -%d ,counter value - %d\n",buffer[in],counter);
        in = (in+1)%BUFFERSIZE;


        }
        
}

void *consumer(void *q)
{      
	   while(1){
       while(counter==0);
       int i = buffer[out];
       out = (out+1)%BUFFERSIZE;
       for(int i=0;i<600000;i++); 	//to simulate consumption
       counter--;
       printf("Consumed Item -%d ,counter value - %d\n",i,counter);
       } 
   
}

int main()
{   
    srand(time(0));
    pthread_t pid1,pid2;
    pthread_create(&pid1,NULL,producer,NULL);
    pthread_create(&pid2,NULL,consumer,NULL);

    pthread_join(pid1,NULL);
    pthread_join(pid2,NULL);

    return 0;
}
