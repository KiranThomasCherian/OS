#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(){
    int n;
    printf("Enter dimension of magic matrix (eg if 3*3 then enter 3) : ");
    scanf("%d",&n);
    int a[20][20];
    printf("Enter the matrix row wise :\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
        scanf("%d",&a[i][j]);
    }
    int dsum=0,rdsum=0;
    for(int i=0;i<n;i++){
    dsum=dsum+a[i][i];                      //main diagonal
    rdsum+= a[i][n - i - 1];                //off diagonal
    }
    int flag=0,rflag=0;
    if(dsum!=rdsum){
        printf("Not magic matrix \n");
        exit(0);
    }
    pid_t pid;
    for(int i=0;i<n;i++)
    {
        pid=vfork();
        if(pid==0){
            printf("A new child process\n");
            for(int j=1;j<n;j++){       //  uniquness
            for(int k=0;k<j;k++){
                if(a[i][k]==a[i][j]){
                rflag=1;
                _exit(0);
            }
            }
            }
        _exit(0);
        }
    }
    int status1;
    while(wait(&status1)>0);
    printf("Here \n");
    if(rflag==1){
        printf("Not a magic matrix \n");
        exit(0);
    }
    for(int i=0;i<n;i++)
    {
        pid=vfork();
        if(pid==0){
            printf("A new child process\n");
            int rsum=0;
            for(int j=0;j<n;j++){       //  rows sum
                rsum+=a[j][i];
            }
        if(rsum!=dsum)
        flag=1;
        _exit(0);
        }
    }
    for(int i=0;i<n;i++)
    {
        pid=vfork();
        if(pid==0){
            printf("A new child process\n");
            int csum=0;
            for(int j=0;j<n;j++){
                csum+=a[i][j];          //column sum
            }
        if(csum!=dsum)
        flag=1;
        _exit(0);
        }
    }
    int status;
    while(wait(&status)>0);

    if(flag==1){
        printf("Not a magic matrix \n");
    }else
    printf("It is a magic matrix!\n");
    printf("Total process : %d (%d for row sums,%d for column sums,%d for unique check,other sums/operations in main)\n",(3*n)+1,n,n,n);

    return 0;
}