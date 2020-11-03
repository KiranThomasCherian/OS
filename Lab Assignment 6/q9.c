//Matrix method used , discribed in document .
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<pthread.h>
void *runner(void *arg);
void *runner1(void *arg);
void twodmatrixmul(int a[2][2],int b[2][2],int c[2][2]);

int n,i,flag;
int arr[2][2]={{1,1},{1,0}};
int temp[2][2]={{0,0},{0,0}};
int final[2][2]={{0,0},{0,0}};
int main(){
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
		if(n%2!=0)
		flag=1;
		for(i=2;i<=n;i=i+2){
		pthread_attr_t attr;
		pthread_attr_init(&attr); 
		pthread_t pid,pid1;
		pthread_create(&pid,&attr,runner,NULL);
		pthread_join(pid,NULL);
		pthread_create(&pid1,&attr,runner1,NULL);
		pthread_join(pid1,NULL);
		}
return 0;
}


		void *runner(void * arg)
		{
		pthread_attr_t attr;
		if(i>2){
		twodmatrixmul(arr,arr,temp);
		int l=1;		
		while(l<((i-3))){
		twodmatrixmul(temp,arr,final);
		temp[0][0]=final[0][0];
		temp[0][1]=final[0][1];
		temp[1][0]=final[1][0];
		temp[1][1]=final[1][1];
		l++;
		}
		final[0][0]=temp[0][0];
		final[0][1]=temp[0][1];
		final[1][0]=temp[1][0];
		final[1][1]=temp[1][1];
		}	
		pthread_exit(NULL);
		}

void *runner1(void *arg)
{
		int f1=1;
		int f2=1;
		int top,bot;		
		top=(final[0][0]*f2)+(final[0][1]*f1);
		bot=(final[1][0]*f2)+(final[1][1]*f1);
		if(i==2)
		{
		top=f2;
		bot=f1;
		}		
		printf(" %d %d",bot,top);
		if((flag==1)&&(i==n-1))
		printf(" %d",(top+bot));
		
		pthread_exit(NULL);
}

void twodmatrixmul(int a[2][2],int b[2][2],int c[2][2]){
c[0][0]=(a[0][0]*b[0][0]) +(a[0][1]*b[1][0]);
c[0][1]=(a[0][0]*b[0][1]) +(a[0][1]*b[1][1]);
c[1][0]=(a[1][0]*b[0][0]) +(a[1][1]*b[1][0]);
c[1][1]=(a[1][0]*b[0][1]) +(a[1][1]*b[1][1]);
}
