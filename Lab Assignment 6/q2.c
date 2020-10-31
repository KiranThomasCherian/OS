#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
void *runner1(void *arg);
void *runner2(void *arg);

int arr[100];
int main(){
   int n; 
    pid_t pid;
    printf("Enter size : ");
    scanf("%d",&n);
   
    printf("Enter elements : ");
    for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
pthread_t ptid1,ptid2;
pthread_attr_t attr;
pthread_attr_init(&attr); 
  
int *nn=&n;
pthread_create(&ptid1,&attr,runner1,nn);
pthread_create(&ptid2,&attr,runner2,nn);
pthread_join(ptid1, NULL);
pthread_join(ptid2, NULL);
printf("Ending main (id:%d)\n ",pthread_self());

return 0;
}
void *runner1(void *arg){
int *n=arg;
        printf("\nAscending sort  by thread: (id:%d)\n ",pthread_self());
        int i,k,j; 
        for (i = 1; i < *n; i++) { 
        k = arr[i]; 
        j = i - 1; 
    while (j >= 0 && arr[j] > k) { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = k; 
    } 
    for(int i=0;i<*n;i++){
            printf("%d ",arr[i]);
        }
    printf("\n");
pthread_exit(NULL);
    }




void *runner2(void *arg){
int *n=arg;
printf("\nDecending sort  by thread: (id:%d)\n ",pthread_self());
        
    for (int j = 1; j <= *n - 1; j++) {
      int i = j - 1;
      int k = arr[j];

      while (i >= 0 && arr[i] < k){
         arr[i+1] = arr[i];
         i--;
      }
      arr[i+1] = k;
   }

   for(int i = 0; i < *n; i++){
      printf( "%d ",arr[i]);
   }   
        printf("\n");
pthread_exit(NULL);
}
