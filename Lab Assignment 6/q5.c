#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<math.h>
void *runner(void *arg);
void *runner1(void *arg);
void *runner2(void *arg);
void *runner3(void *arg);
int n;
int arr[50];
pthread_mutex_t lock;
pthread_t pid,pid1,pid2,pid3;
pthread_attr_t attr;

int main(){

printf("Enter the size  : ");
scanf("%d",&n);
printf("Enter the elements : ");
for(int i=0;i<n;i++)
scanf("%d",&arr[i]);
if (pthread_mutex_init(&lock, NULL) != 0) { 
        printf("\n mutex init has failed\n"); 
        return 1; 
    }

pthread_attr_init(&attr);
pthread_create(&pid,&attr,runner,NULL);
pthread_create(&pid1,&attr,runner1,NULL);

pthread_join(pid,NULL);
pthread_join(pid1,NULL);
pthread_join(pid2,NULL);
pthread_join(pid3,NULL);
pthread_mutex_destroy(&lock);
return 0;
}
void *runner(void *arg){
pthread_mutex_lock(&lock);
int i,key,j; 
    for(i = 1; i < n; i++){ 
        key = arr[i]; 
        j = i - 1; 
        while(j >= 0 && arr[j] > key){ 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    } 
pthread_mutex_unlock(&lock);
pthread_create(&pid2,&attr,runner2,NULL);
pthread_create(&pid3,&attr,runner3,NULL);
pthread_exit(NULL);
}
void *runner2(void *arg){
	if(n%2!=0)
	printf("Median = %d (After sorting )\n",arr[n/2]);
	else
	printf("Median = %d (After sorting )\n",(arr[n/2]+arr[(n/2)-1])/2);
	pthread_exit(NULL);
	}
void *runner1(void * arg){
	float sum=0.0;
	for(int i=0;i<n;i++)//{
	//printf("%d",arr[i]);
	sum+=arr[i];//}
	printf("Mean = %0.3f \n",sum/n);
	pthread_exit(NULL);
	}
void *runner3(void *arg){
    int mv = 0,mc = 0, i, j;
	for(i = 0; i < n; ++i) {
    int count = 0;
    for(j = 0; j <=i; ++j) {
    if(arr[j] == arr[i])
     ++count;
     }   
    if(count > mc) {
       mc = count;
       mv = arr[i];
      }
   }
	printf("Mode =%d (%d times) -note if tie only 1 will be shown\n",mv,mc);
pthread_exit(NULL);
}	
