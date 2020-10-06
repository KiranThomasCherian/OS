#include<stdio.h>
#include<unistd.h>
int main(){
    int n;
    pid_t pid;
    printf("Enter n : ");
    scanf("%d",&n);
    pid=fork();
    if(pid==0){
        printf("Inside child  : even numbers till %d : ",n);
        int s=0;
        for(int i=0;i<=n;i=i+2){
            s=s+i;
            printf("%d ",i);
        }
        printf("\nsum of even terms by child : %d \n",s);
    }
    else if(pid>0){
        usleep(200000);
        //printf("\nOdd series by parent: ");
         printf("Inside parent: odd numbers till %d : ",n);
        int s=0;
        for(int i=1;i<=n;i=i+2){
            s=s+i;
            printf("%d ",i);
    }
    printf("\nsum of odd terms by parent : %d \n",s);
    }
    else
    {
        printf("Fork failed.. exiting..");
    }
    return 0;
}