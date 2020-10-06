#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
int n1,m1,n2,m2;
int a[20][20],b[20][20],c[20][20];
pid_t pid;
printf("Enter dimensions of matrix 1 ( row column ) : ");
scanf("%d%d",&n1,&m1);
printf("Enter the matrix along the rows : \n");
for(int i=0;i<n1;i++)
for(int j=0;j<m1;j++)
scanf("%d",&a[i][j]);

printf("Enter dimensions of matrix 2 ( row column ) : ");
scanf("%d%d",&n2,&m2);
if(m1!=n2){
printf("\n Can't multiply ,exiting \n");
exit(0);
}
printf("Enter the matrix along the rows : \n");
for(int i=0;i<n2;i++)
for(int j=0;j<m2;j++)
scanf("%d",&b[i][j]);

printf("Matrix A\n");
for(int i=0;i<n1;i++)
{
for(int j=0;j<m1;j++)
printf("  %d",a[i][j]);
printf("\n");
}printf("Matrix B\n");
for(int i=0;i<n2;i++)
{
for(int j=0;j<m2;j++)
printf("  %d",b[i][j]);
printf("\n");
}
for(int i=0;i<n1;i++){
for(int j=0;j<m2;j++){
pid=vfork();
if(pid==0){
c[i][j]=0;
for(int k=0;k<m1;k++)
c[i][j]+=(a[i][k]*b[k][j]);
printf("	New process\n");
_exit(0);
}
}
}

int status=0;
while(wait(&status)>0);
printf("Answer : \n");
for(int i=0;i<n1;i++)
{
for(int j=0;j<m2;j++)
printf("  %d",c[i][j]);
printf("\n");
}
printf("Total child process created : %d\n",(n1*m2));
return 0;
}
