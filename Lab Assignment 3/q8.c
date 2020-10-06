//Matrix method used , discribed in document .
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
void twodmatrixmul(int a[2][2],int b[2][2],int c[2][2]);
int main(){
int n;
printf("Program to generate fibinocci series,Note :starting from 1 \nenter n : ");
scanf("%d",&n);
if(n==1){
            printf(" 1 ");
        }
else if(n<=0){
            printf("Invalid n used \n");
        }
else if(n==2){
            printf(" 1  1  ");
        }
        else{
		pid_t pid;
		int flag=0;
		if(n%2!=0)
		flag=1;
		for(int i=2;i<=n;i=i+2){
		int finalrhs[2][2]={{0,0},{0,0}};
		pid=vfork();

if(pid==0)
		{
		if(i>2){
		int c[2][2]={{0,0},{0,0}};
		int c1[2][2]={{0,0},{0,0}};
		int arr[2][2]={{1,1},{1,0}};
		twodmatrixmul(arr,arr,c);
		int l=1;		
		while(l<((i-3))){
		twodmatrixmul(c,arr,c1);
		c[0][0]=c1[0][0];
		c[0][1]=c1[0][1];
		c[1][0]=c1[1][0];
		c[1][1]=c1[1][1];
		l++;
		}
		finalrhs[0][0]=c[0][0];
		finalrhs[0][1]=c[0][1];
		finalrhs[1][0]=c[1][0];
		finalrhs[1][1]=c[1][1];
//		printf(" %d %d %d %d ",finalrhs[0][0],finalrhs[0][1],finalrhs[1][0],finalrhs[1][1]);
		}	
		_exit(0);
		}
else if(pid>0){
		wait(NULL);
		int f1=1;
		int f2=1;
		int top,bot;		
		top=(finalrhs[0][0]*f2)	+(finalrhs[0][1]*f1);
		bot=(finalrhs[1][0]*f2)	+(finalrhs[1][1]*f1);
		if(i==2)
		{
		top=f2;
		bot=f1;
		}		
		printf(" %d %d",bot,top);
		if((flag==1)&&(i==n-1))
		printf(" %d",(top+bot));
		}
//		printf("\n");
		}
		}
return 0;
}


 void twodmatrixmul(int a[2][2],int b[2][2],int c[2][2]){
c[0][0]=(a[0][0]*b[0][0]) +(a[0][1]*b[1][0]);
c[0][1]=(a[0][0]*b[0][1]) +(a[0][1]*b[1][1]);
c[1][0]=(a[1][0]*b[0][0]) +(a[1][1]*b[1][0]);
c[1][1]=(a[1][0]*b[0][1]) +(a[1][1]*b[1][1]);
}
