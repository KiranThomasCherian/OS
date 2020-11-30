#include<pthread.h>
#include<unistd.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>


pthread_mutex_t mutex,mutex2;
int nowreading = 0;
int count=0;

struct dictionary 
{
	char word[50];
	char primary[100];
	char secondary[100];
};

struct dictionary arr[10];
void *writer(void *arg)
{   
	if(count<4){
	char word[100];						//only 4 words in dictonary
    pthread_mutex_lock(&mutex);
    printf("Enter word to enter : ");
    scanf("%s",word);
    int flag=0;
    for(int i=0;i<count;i++)
    {
    	if(strcmp(arr[i].word,word)==0)
    	{
    		printf("Already present.\n");
    		flag=1;
    		break;
    	}
    }
    if(flag==0)
    {
    strcpy(arr[count].word,word);
    printf("Enter meaning and secondard meaning : ");
    scanf("%s",arr[count].primary);
    scanf("%s",arr[count].secondary);
    printf("[added - %s]\n",arr[count].word);
    count++;
	}
    pthread_mutex_unlock(&mutex);
	}
	pthread_exit(NULL);
}
void *consumer(void *arg)
{   
	//if(count>0){
    pthread_mutex_lock(&mutex2);
    nowreading++;
    if(nowreading == 1) {
        pthread_mutex_lock(&mutex); // block the writer
    }
    //pthread_mutex_unlock(&mutex2);

    char search[100];
    printf("Enter word to wanna search: ");
    scanf("%s",search);
    int beg=0;
 	int end=count;
 	int flag=0;
 	while(beg<=end)
 	{
 		int mid=(beg+end)/2;
 		if (strcmp(search,arr[mid].word)==0)
 		{
 			printf("Primary Meaning: %s  ,", arr[mid].primary);
 			printf("Secondary Meaning: %s\n", arr[mid].secondary);
        	flag=1;
        	break;
 		}
 		else if(strcmp(search,arr[mid].word)>0)
 		{
 			beg=mid+1;
 		}
 		else
 		{
 			end=mid-1;
 		}
 	}
 	if(flag==0)
 	printf("Word not found\n");
    //pthread_mutex_lock(&mutex2);
    nowreading--;
    if(nowreading == 0) 
    {
        pthread_mutex_unlock(&mutex); //last reader unlocks
    }
    pthread_mutex_unlock(&mutex2);
//}
pthread_exit(NULL);
}

int main()
{   
	printf("Writer should give data in ascending fashion!!\n");
    pthread_t pid1[4],pid2[5];
    pthread_mutex_init(&mutex, NULL);
    pthread_mutex_init(&mutex2, NULL);
    int i;
    for( i = 0; i < 4; i++) {
        pthread_create(&pid1[i],NULL,writer,NULL);
        pthread_create(&pid2[i],NULL,consumer,NULL);
    }
        pthread_create(&pid2[i],NULL,consumer,NULL);		//remaining readers  --(increase to 20 as per question)


     for(int i = 0; i < 4; i++) {
        pthread_join(pid1[i],NULL);
    }   
 
    for(int i = 0; i < 5; i++) {
        pthread_join(pid2[i],NULL);
    }
    pthread_mutex_destroy(&mutex);
    pthread_mutex_destroy(&mutex2);


    return 0;
    
}
