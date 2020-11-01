#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#include<unistd.h>
int isprime[150];
int n;
void *runner(void *arg);
void *runner2(void *arg);
int main(int argc ,char *argv[]){
		if(argc <=1){
		printf("Use cmd line input ,exiting\n");
		exit(0);
		}
        n=atoi(argv[1]);
		int i;
        for (i = 0; i <=n; ++i)
        isprime[i] = 1;
		pthread_t pid;
		pthread_attr_t attr;
		pthread_attr_init(&attr);
		pthread_create(&pid,&attr,runner,NULL);
		pthread_join(pid,NULL);  
        for(int i=2;i<=n;i++){
            if(isprime[i]==1){
                printf("%d ",i);
            }
        } 
		return 0;
		}

void *runner(void *arg) {   
		for(int i=2;i*i<=n;i++){
            //printf(" \n %d ",isprime[i]);
            if(isprime[i]){
			pthread_t pid1;
			pthread_attr_t attr;
			pthread_attr_init(&attr);
			pthread_create(&pid1,&attr,runner2,&i);
			usleep(0);			//for switch as no join

            }
        }
		pthread_exit(NULL);

    }
void *runner2(void * arg){
	int *i=(int *)arg;
	int it=*i;
    for(int j=(it*it);j<=n;j=j+it)
    isprime[j]=0;
	pthread_exit(NULL);
	}
