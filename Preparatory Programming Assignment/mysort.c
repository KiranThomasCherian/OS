#include <stdio.h>        
#include<stdlib.h>
#include<string.h>
int funselect(int ,int ,int);
int main(int argc, char *argv[])                  
{
if(argc ==2&&!strcmp(argv[1],"-help")){
		printf("Program to sort array of integers \nUsage ./mysort <size> <1/2> <num1> <num2> ...\nUse 1 for ascending and 2 for descending");
		exit(0);
	}
if(argc <=3){
    printf("Not enough arguments ");
    exit(0);
}
int s=atoi(argv[1]);
if(3+s!=argc){
    printf("specified amount of numbers should be entered,exiting");
    exit(0);
}
if(atoi(argv[2])>=3||atoi(argv[2])<=0){
    printf("Use 1 for ascending ,2 for decendending, try again..");
    exit(0);
}
int arr[50],k=0;
for(int i=3;i<argc;i++){
int ss=0;
float sss=0;
ss+=atoi(argv[i]);
sss+=atof(argv[i]);
if(sss>ss){
     printf("Non integers given,exiting ");
                exit(0);
}
if(atoi(argv[i])==0&&strcmp(argv[i],"0"))
            {
                printf("Non integers given,exiting ");
                exit(0);
            }
arr[k++]=atoi(argv[i]);
}
for (int i = 0;i < k-1;i++)                  
{
for (int j = 0;j < k-i-1; j++)            
	{
            if(((atoi(argv[2])==1)&&arr[j]>arr[j+1])||( (atoi(argv[2])==2)&&arr[j]<arr[j+1]))         
			{
            int temp;
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
			}  
		}
	}

printf("After sorting : ");
for(int i=0;i <k; i++){
    printf(" %d ",arr[i]);
}
}