#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include<time.h>
#include<unistd.h>
#define BUFFERSIZE 8
// 0 - producer , 1- consumer
int flag[2]={0,0};
int turn;
int counter=0;
int in=0;
int out=0;
int buffer[BUFFERSIZE];
int cc=0;
void *producer(void *q)
{   
        while(1){
		flag[0]=1;
		turn=1;
		while(flag[1]&&turn==1);

		if(counter==BUFFERSIZE){
		flag[0]=0;
		}
		else{
        //for(int i=0;i<100000;i++); 	//to simulate production 
        buffer[in] = cc++;
        counter++;
        printf("Produced Item -%d ,counter value - %d\n",buffer[in],counter);
        in = (in+1)%BUFFERSIZE;
		flag[0]=0;
		}


        }
        
}

void *consumer(void *q)
{      
	   while(1){



	   flag[1]=1;
	   turn=0;
	   while(flag[0]&&turn==0);


	   if(counter==0){
       flag[1]=0;}
       else{
       int i = buffer[out];
       for(int j=0;j<500000;j++); 	//to simulate consumption
       counter--;
       out = (out+1)%BUFFERSIZE;       
       printf("Consumed Item -%d ,counter value - %d\n",i,counter);
       flag[1]=0;
       }

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

