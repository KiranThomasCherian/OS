#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
int main(){

    int n;
    pid_t pid;
    printf("Enter n : ");
    scanf("%d",&n);
    pid=fork();
    if(pid==0){
        if(n<=1){
            printf("Invalid n, least possible prime is 2 \n");
            exit(0);
        }
        printf("Inside child  : prime numbers till %d : ",n);
        int isprime[100];
        int i;
        for (i = 0; i <=n; ++i)
        isprime[i] = 1;
        //int array[1024] = {[0 ... 1023] = 5};
        //memset(isprime,1,n*sizeof(isprime[0]));
        for(int i=2;i*i<=n;i++){
            //printf(" \n %d ",isprime[i]);
            if(isprime[i]){
                for(int j=i*i;j<=n;j=j+i)
                isprime[j]=0;
            }
        }
        for(int i=2;i<=n;i++){
            if(isprime[i]==1){
                printf("%d ",i);
            }
        }
     
        printf("\n");
    }
    else if(pid>0){
        usleep(200000);
        //printf("\nOdd series by parent: ");
         printf("Inside parent: first %d fibinocci numbers : ",n);
        if(n==1){
            printf(" 0 ");
        }
        else if(n<=0){
            printf("Invalid n used");
        }
        else if(n==2){
            printf(" 0  1  ");
        }
        else{
                    int a=0,b=1,c;
                    printf(" %d %d",a,b);
                    int s =2;
                    while(s++!=n){
                        c=a+b;
                        printf(" %d ",c);
                        a=b;
                        b=c;
                    }
        }
    printf("\n");
    }
    else
    {
        printf("Fork failed.. exiting..");
    }
    return 0;
}