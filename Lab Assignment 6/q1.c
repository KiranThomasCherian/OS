#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<math.h>
int i;
struct both{
int ival;
int sval;
};
void *runner(void *arg);
void *runner2(void *arg);
int main(){
int n;
printf("Enter the range (>=1) : ");
scanf("%d",&n);
pthread_t pid;
pthread_attr_t attr;
pthread_attr_init(&attr);
for(i=1;i<=n;i++){
pthread_create(&pid,&attr,runner,NULL);
pthread_join(pid,NULL);
}
return 0;
}

void *runner(void *arg){
	int j=i;
	//int *sum=(int *)malloc(sizeof(int));
	int sum=0;    
	while(j>0){
    int q=pow((j%10),3);
    sum=(sum)+q;
    j=j/10;
    }
	//printf("s %d i %d \n",sum,i);
	pthread_t pid1;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	struct both* si=(struct both *)malloc(sizeof(struct both));
	si->ival=i;
	si->sval=sum;	
	pthread_create(&pid1,&attr,runner2,si);
	//free(si);
	//printf("Exiting\n");
	pthread_exit(NULL);
	}
void *runner2(void * arg){
	struct both *si=(struct both *)arg;
	//printf("ss %d ii %d \n",si->sval,si->ival);
	if(si->ival==si->sval)
	printf(" %d\n",si->ival);
	pthread_exit(NULL);
	}

	
