#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<sys/wait.h>
#include<unistd.h>
int main(){
    int n;
    pid_t pid;
    printf("Enter n : ");
    scanf("%d",&n);
  
    int i,j,q,s,k;
    i=1;
    k=0;
    s=0;
    int dc=0;
    int da[10];
    int out[100];
    for(int i=0;i<=n;i++)
    {
    pid=vfork();
    if(pid==0){
        //printf("child %d \n",i);
           j=i;
           dc=0;
           s=0;
           while(j>0){
            //q=pow((j%10),3);
            da[dc++]=j%10;
            j=j/10;
           // s=s+q;
            //printf("%d %d %d\n",q,j,s);
          }
            _exit(0);
        }
    else if(pid>0){
        wait(NULL);
        //printf("par %d %d \n",i,s);
        for(int l=0;l<dc;l++){
            s=s+pow((da[l]),3);
        }
        if(s==i)
        out[k++]=i;
        if(i==n){
        printf(" Armstrong numbers till %d : ",n);
        for(int l=0;l<k;l++){
            printf("%d ",out[l]);
        }
        printf("\n");
        }

    }
    else
    {
        printf("Fork failed.. exiting..");
        exit(0);
    }
    }
    return 0;
}
