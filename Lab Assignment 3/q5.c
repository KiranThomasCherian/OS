#include<stdio.h>
#include<unistd.h>
int main(){
    int n;
    pid_t pid;
    printf("Enter size : ");
    scanf("%d",&n);
    int arr[100];
    printf("Enter elements : ");
    for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
    pid=fork();
    if(pid==0){
        printf("\nDecending sort  by child: ");
        
    for (int j = 1; j < n - 1; j++) {
      int i = j - 1;
      int k = arr[j];

      while (i >= 0 && arr[i] < k){
         arr[i+1] = arr[i];
         i--;
      }
      arr[i+1] = k;
   }

   for(int i = 0; i < n; i++){
      printf( "%d ",arr[i]);
   }   
        printf("\n");

    }
    else if(pid>0){
        usleep(200000);
        printf("\nAscending sort  by parent: ");
        int i,k,j; 
        for (i = 1; i < n; i++) { 
        k = arr[i]; 
        j = i - 1; 
    while (j >= 0 && arr[j] > k) { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = k; 
    } 
    for(int i=0;i<n;i++){
            printf("%d ",arr[i]);
        }
    printf("\n");
    }
    else
    {
        printf("Fork failed.. exiting..");
    }
    return 0;
}