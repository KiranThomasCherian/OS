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

int (*op)(int,int,int)=&funselect;

// for (int i = 3;i < (3+s-1);i++)                  
// {
// for (int j = 3;j < ((3+s-1)-(i-3)); j++)            
// 	{
           
// 			if((atoi(argv[j])==0&&strcmp(argv[j],"0"))||(atoi(argv[j+1])==0&&strcmp(argv[j+1],"0")))
//             {
//                 printf("Non integers given,exiting ");
//                 exit(0);
//             }
//             if((*op)(atoi(argv[2]),atoi(argv[j]),atoi(argv[j+1])))            
// 			{
// 			 char temp[10]="\0";
//              printf("here  %d %d %s\n",atoi(argv[j]),atoi(argv[j+1]),temp);
//             //  snprintf(temp,strlen(argv[j]),"%s\n",argv[j]);
//             //  snprintf(argv[j],strlen(argv[j+1]),"%s\n",argv[j+1]);
//             //  snprintf(argv[j+1],strlen(argv[j]),"%s\n",argv[j]);
//              strcpy(temp, argv[j]); 
//                          printf("here  %d %d %s %s %s\n",atoi(argv[j]),atoi(argv[j+1]),temp,argv[j],argv[j+1]);
//              strcpy(argv[j],argv[j+1]); 
//                          printf("here  %d %d %s %s %s\n",atoi(argv[j]),atoi(argv[j+1]),temp,argv[j],argv[j+1]);
//              strcpy(argv[j+1], temp); 
//             printf("here  %d %d %s %s %s\n\n",atoi(argv[j]),atoi(argv[j+1]),temp,argv[j],argv[j+1]);
// 			}  
//             // int l=((3+s-1-3)-i);
//             //  printf(" %d %d" ,j,l);
// 		}
// 	}
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
            if((*op)(atoi(argv[2]),arr[j],arr[j+1]))            
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
int funselect(int op,int a,int b){
    if (op==1)
    return((a>b)?1:0);
    else
    return((a<b)?1:0) ;  
}