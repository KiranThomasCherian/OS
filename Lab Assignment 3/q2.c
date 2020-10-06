#include<stdio.h>
#include<unistd.h>
int main(){
    int n;
    pid_t pid;
    printf("Enter n : ");
    scanf("%d",&n);
    pid=fork();
    if(pid==0){
        printf("Even series by child: ");
        for(int i=1;i<=n;i++){
            printf("%d ",2*i);
        }
        printf("\n");
    }
    else if(pid>0){
        usleep(200000);
        printf("\nOdd series by parent: ");
        for(int i=0;i<n;i++){
            printf("%d ",(2*i + 1));
    }
    printf("\n");
    }
    else
    {
        printf("Fork failed.. exiting..");
    }
    return 0;
}